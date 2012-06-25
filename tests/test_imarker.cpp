// Unit Test Framework Includes
#include "UnitTest++.h"

// Supporting Includes

// File To Test
#include "imarker.h"

using namespace UnitTest;

//-----------------------------------------------------------------------------
// Helper Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Begin Unit Tests
//-----------------------------------------------------------------------------
namespace {
    //-------------------------------------------------------------------------
    // Test location() setter and getter
    //-------------------------------------------------------------------------
    TEST(Verify_location_returns_the_current_index_location)
    {
        IMarker marker;

        CHECK( 0 == marker.location() );
        marker.location(1);
        CHECK( 1 == marker.location() );
        marker.location(2);
        CHECK( 2 == marker.location() );
        marker.location(42);
        CHECK( 42 == marker.location() );
    }

    //-------------------------------------------------------------------------
    // Test advance() method
    //-------------------------------------------------------------------------
    TEST(Verify_advance_increments_the_index_value)
    {
        IMarker marker;
        CHECK( 0 == marker.location() );
        marker.advance();
        CHECK( 1 == marker.location() );
        marker.advance();
        CHECK( 2 == marker.location() );
        marker.advance();
        CHECK( 3 == marker.location() );
    }

    //-------------------------------------------------------------------------
    // Test mark() and release() methods
    //-------------------------------------------------------------------------
    TEST(Verify_mark_and_release_will_mark_indexes_and_roll_back_to_those_locations)
    {
        IMarker marker;
        CHECK( 0 == marker.mark() );
        marker.location(10);
        CHECK( 10 == marker.mark() );
        marker.location(42);
        marker.release();
        CHECK( 10 == marker.location() );
        marker.release();
        CHECK( 0 == marker.location() );
    }

    //-------------------------------------------------------------------------
    // Test isMarked() method
    //-------------------------------------------------------------------------
    TEST(Verify_isMarked_returns_false_if_no_marks)
    {
        IMarker marker;
        CHECK( false == marker.isMarked() );
    }

    TEST(Verify_isMarked_returns_true_if_marked)
    {
        IMarker marker;
        marker.mark();
        CHECK( true == marker.isMarked() );
    }
}
