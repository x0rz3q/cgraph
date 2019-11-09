build:
	mkdir build
	cd build; cmake ..
	cd build; make
test: build
	./build/UnitTest
