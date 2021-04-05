common = main.cpp common/bsdf.cpp common/build_scene.cpp common/distribution.cpp common/generate_hit.cpp common/random.cpp common/ray_sample.cpp

cpu = cpu/kernals.cpp
gpu = gpu/kernals.cpp gpu/info.cpp

.PHONY: cpu cpu-gpu format

cpu:
	c++ -O3 -g $(common) $(cpu)

cpu-gpu:
	nvcc -O3 -g -x cu -rdc=true $(common) $(cpu) $(gpu)

format:
	find -not -path './.*' | grep -E '(*.h|*.cpp)' | xargs clang-format -style=LLVM -i
