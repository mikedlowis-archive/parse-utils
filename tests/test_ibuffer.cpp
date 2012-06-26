// Unit Test Framework Includes
#include "UnitTest++.h"

// Supporting Includes
#include <iostream>

// File To Test
#include "ibuffer.h"

using namespace UnitTest;

//-----------------------------------------------------------------------------
// Helper Functions and Classes
//-----------------------------------------------------------------------------
class TestIBuffer : public IBuffer
{
    public:
        unsigned int cur_size;
        unsigned int times_size_called;
        unsigned int times_clear_called;
        unsigned int times_load_called;

        TestIBuffer() : cur_size(0),
                        times_size_called(0),
                        times_clear_called(0),
                        times_load_called(0) {}

        unsigned int size() {
            times_size_called++;
            return cur_size;
        }

        void clear() {
            times_clear_called++;
            cur_size = 0;
        }

        void load() {
            times_load_called++;
            cur_size++;
        }
};
//-----------------------------------------------------------------------------
// Begin Unit Tests
//-----------------------------------------------------------------------------
namespace {
    //-------------------------------------------------------------------------
    // Test consume() method
    //-------------------------------------------------------------------------
    TEST(Verify_consume_clears_the_current_buffer_when_not_marked_and_synced)
    {
        TestIBuffer buffer;
        buffer.cur_size = 1;

        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );
        buffer.consume();
        CHECK( 1 == buffer.cur_size );
        CHECK( 0 == buffer.location() );
        CHECK( 3 == buffer.times_size_called );
        CHECK( 1 == buffer.times_clear_called );
    }

    TEST(Verify_consume_advances_the_index_when_the_buffer_is_out_of_sync)
    {
        TestIBuffer buffer;
        buffer.cur_size = 2;

        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );
        buffer.consume();
        CHECK( 2 == buffer.cur_size );
        CHECK( 1 == buffer.location() );
        CHECK( 3 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
    }

    TEST(Verify_consume_does_not_consume_when_marked)
    {
        TestIBuffer buffer;
        buffer.cur_size = 1;
        buffer.mark();

        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );
        buffer.consume();
        CHECK( 2 == buffer.cur_size );
        CHECK( 1 == buffer.location() );
        CHECK( 3 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
    }

    //--------------------
    // TODO: Check if this test is needed.
    //--------------------
    //TEST(Verify_consume_handles_a_call_when_not_initialized)
    //{
    //    TestIBuffer buffer;

    //    CHECK( 0 == buffer.times_size_called );
    //    CHECK( 0 == buffer.times_clear_called );
    //    CHECK( 0 == buffer.location() );
    //    buffer.consume();
    //    CHECK( 2 == buffer.cur_size );
    //    CHECK( 1 == buffer.location() );
    //    CHECK( 3 == buffer.times_size_called );
    //    CHECK( 0 == buffer.times_clear_called );
    //}

    //-------------------------------------------------------------------------
    // Test sync() method
    //-------------------------------------------------------------------------
    TEST(Verify_sync_loads_1_item_of_input_and_updates_the_index)
    {
        TestIBuffer buffer;
        buffer.cur_size = 0;
        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );

        // Sync from 0 to 1
        buffer.sync(1);
        CHECK( 1 == buffer.cur_size );
        CHECK( 0 == buffer.location() );
        CHECK( 2 == buffer.times_size_called );
        CHECK( 1 == buffer.times_load_called );
    }

    TEST(Verify_sync_loads_1_item_of_input_and_updates_the_index_so_that_the_buffer_contains_two_items)
    {
        TestIBuffer buffer;
        buffer.cur_size = 1;
        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );

        // Sync from 1 to 2
        buffer.sync(2);
        CHECK( 2 == buffer.cur_size );
        CHECK( 0 == buffer.location() );
        CHECK( 2 == buffer.times_size_called );
        CHECK( 1 == buffer.times_load_called );
    }

    TEST(Verify_sync_should_detect_that_data_is_already_loaded_and_do_nothing)
    {
        TestIBuffer buffer;
        buffer.cur_size = 2;
        CHECK( 0 == buffer.times_size_called );
        CHECK( 0 == buffer.times_clear_called );
        CHECK( 0 == buffer.location() );

        // Do nothing if already synced
        buffer.sync(1);
        CHECK( 2 == buffer.cur_size );
        CHECK( 0 == buffer.location() );
        CHECK( 2 == buffer.times_size_called );
        CHECK( 0 == buffer.times_load_called );
    }

    //-------------------------------------------------------------------------
    // Test fill() method
    //-------------------------------------------------------------------------
    TEST(Verify_fill_loads_0_items_from_input)
    {
        TestIBuffer buffer;
        CHECK( 0 == buffer.times_load_called );
        CHECK( 0 == buffer.cur_size );
        buffer.fill(0);
        CHECK( 0 == buffer.cur_size );
        CHECK( 0 == buffer.times_load_called );
    }

    TEST(Verify_fill_loads_1_item_from_input)
    {
        TestIBuffer buffer;
        CHECK( 0 == buffer.times_load_called );
        CHECK( 0 == buffer.cur_size );
        buffer.fill(1);
        CHECK( 1 == buffer.cur_size );
        CHECK( 1 == buffer.times_load_called );
    }

    TEST(Verify_fill_loads_2_items_from_input)
    {
        TestIBuffer buffer;
        CHECK( 0 == buffer.times_load_called );
        CHECK( 0 == buffer.cur_size );
        buffer.fill(2);
        CHECK( 2 == buffer.cur_size );
        CHECK( 2 == buffer.times_load_called );
    }
}
