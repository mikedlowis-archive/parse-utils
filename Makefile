###############################################################################
#
# Name:    Parse Utils
# Type:    Library
# Author:  Mike Lowis
# License: BSD 2-Clause
#
###############################################################################

# Utility Function Definitions
#-----------------------------
# Function for generating an file list
flist = $(shell env find $(1) -name *.$(strip $(2)) -print)

# Function for generating an file list
dlist = $(shell env find $(1) -type d -print)

# Function for generating an include list
incdirs = $(addprefix -I, $(call dlist, $(1)))

# Function for generating file dependencies
define make-depend
  $(CXX) $(CXXFLAGS) -M $1 | \
  sed -e 's,\($(notdir $2)\) *:,$(dir $2)\1 $(subst .o,.d,$2): ,' \
  > $(subst .o,.d,$2)
endef

# Project and Artifact Names
#---------------------------
PROJ_NAME   = parseutils
SHARED_NAME = lib$(PROJ_NAME).lib
STATIC_NAME = lib$(PROJ_NAME).a

# File and Directory Settings
#----------------------------
# Root Directories
SRC_ROOT  = source/
# File Extensions
SRC_EXT = cpp
# Source File Lists
SRC_FILES  = $(call flist, $(SRC_ROOT), $(SRC_EXT))

# Object File Lists
SRC_OBJS = $(SRC_FILES:%.$(SRC_EXT)=%.o)
# Dependecy File Lists
SRC_DEPS  = $(SRC_OBJS:%.o=%.d)
# Include Directories
INC_DIRS = $(call incdirs, $(SRC_ROOT))


# Compiler and Linker Options
#----------------------------
CXXFLAGS = $(INC_DIRS) -Wall -fPIC
ARFLAGS  = rcs

# Build Rules
#------------
all: shared static
shared: $(SHARED_NAME)
static: $(STATIC_NAME)

# Binaries
$(SHARED_NAME): $(SRC_OBJS)
	@echo Linking $@...
	@$(CXX) $(CXXFLAGS) -shared -o $@ $(SRC_OBJS)

$(STATIC_NAME): $(SRC_OBJS)
	@echo Linking $@...
	@$(AR) $(ARFLAGS) -o $@ $(SRC_OBJS)

# Object Files
$(SRC_OBJS): %.o : %.$(SRC_EXT)
	@echo $<
	@$(call make-depend,$<,$@)
	@$(CXX) -c $(CXXFLAGS) -o $@ $<

# Cleanup
clean:
	@$(RM) $(SRC_OBJS)
	@$(RM) $(SRC_DEPS)
	@$(RM) $(SHARED_NAME)
	@$(RM) $(STATIC_NAME)

