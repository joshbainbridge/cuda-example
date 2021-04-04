common = main.cpp common/bsdf.cpp common/distribution.cpp common/random.cpp common/ray_sample.cpp

cpu = cpu/kernal.cpp
gpu = gpu/kernal.cpp gpu/info.cpp

.PHONY: cpu cpu-gpu format

cpu:
	c++ -g $(common) $(cpu)

cpu-gpu:
	nvcc -x cu -rdc=true $(common) $(cpu) $(gpu)

format:
	find -not -path './.*' | grep -E '(*.h|*.cpp)' | xargs clang-format -style=LLVM -i
