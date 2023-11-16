run:
	@cd ./build;\
		cmake ..;\
		make
	@./build/aicc

deploy:
	@cd ./build;\
		cmake -DCMAKE_CXX_FLAGS_RELEASE="-O3" ..;\
		make

test:
	@cd ./build;\
		cmake ..;\
		make
	@./build/tests