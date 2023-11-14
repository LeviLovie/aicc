run:
	@cd ./build;\
		cmake ..;\
		make
	@./build/aicc

test:
	@cd ./build;\
		cmake ..;\
		make
	@./build/tests