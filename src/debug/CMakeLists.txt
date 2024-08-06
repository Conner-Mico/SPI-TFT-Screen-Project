add_custom_target(
  flash
  COMMENT "Flashing elf..."
  COMMAND openocd -f ../../../debug/openocd.cfg -c "program ../app/application verify reset exit")