# Credit for the Auto-dependecy generation portion
# of this file goes to Tom Tromey <tromey@cygnus.com>.
# This file is based on a post that focused on
# this method. The post can be found at:
# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
# Adapted for SDL et al. by Zackary Sullivan

CXX = clang++

DEPDIR := .deps
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

CXXFLAGS = -g -W -Wall 

LDFLAGS = -lm

OBJS = $(shell find . -regex ".*\.cpp" -printf "%P " | sed 's/.cpp/.o/g')

EXEC = run

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

%.o: %.cpp
%.o: %.cpp $(DEPDIR)/%.d
	@echo "Creating Object $@"
	@$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@
	@mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

$(EXEC): $(OBJS)
	@echo "Using $(CXX)"
	@echo "Creating Executable $@"
	@$(CXX) $(CXXFLAGS) main.cpp linkedList.cpp linkedList.h node.h

clean:
	@echo "Deleting Objects"
	@rm -rf $(OBJS)
	@echo "Deleting Executable"
	@rm -rf $(EXEC)
	@echo "Deleting Dependecy List"
	@rm -rf $(DEPDIR)
	@echo "Deleting Images"
	@rm -rf frames/*.bmp

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(OBJS))))
