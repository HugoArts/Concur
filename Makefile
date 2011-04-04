BUILDDIR= build

.PHONY: all clean

# simply invoke the Makefile in the builddir
all clean assemble concur:
	$(MAKE) -C $(BUILDDIR) $@
