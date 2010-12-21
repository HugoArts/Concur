BUILDDIR= build

.PHONY: all clean

# simply invoke the Makefile in the builddir
all clean:
	$(MAKE) -C $(BUILDDIR) $@
