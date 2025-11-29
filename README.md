# STM32F429-TouchGFX
A repository of demos for STM32F429I-DISC1 development kit

## 注意事项 
需要注意的是，用TouchGFX Designer编译下载时，我的Cube Programmer不是默认路径，需要到<你的项目>/gcc/include/cube_programmer.mk，将里面有关cube_programmer的路径进行修改，此处我的cube Programmer安装到了E盘下的Program Files文件夹下：

program_files_win32 = /e/Program Files (x86)

program_files_win64 = /e/Program Files

program_files_CLT = /e/ST/STM32CubeCLT/STM32CubeCLT/

如果你是安装在C盘，应该改回

program_files_win32 = /c/Program Files (x86)

program_files_win64 = /c/Program Files

program_files_CLT = /c/ST/STM32CubeCLT/STM32CubeCLT/
