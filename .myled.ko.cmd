cmd_/home/ubuntu/robot_system/myled.ko := ld -r  -EL  -maarch64elf  --build-id  -T ./scripts/module-common.lds -T ./arch/arm64/kernel/module.lds -o /home/ubuntu/robot_system/myled.ko /home/ubuntu/robot_system/myled.o /home/ubuntu/robot_system/myled.mod.o;  true