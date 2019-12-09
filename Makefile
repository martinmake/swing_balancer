.PHONY: all
all:
	@mkdir -p build && cd build && cmake -Wno-dev .. && $(MAKE)

.PHONY: debug
debug:
	@mkdir -p build && cd build && cmake -Wno-dev -DCMAKE_BUILD_TYPE=Debug .. && $(MAKE)
