保持和原有impala的目录一致
依赖impala的toolchain目录，系统依赖文件需要在toolchain中存在
依赖文件提取copy到对应目录，不自动化查找和生成文件，可以与impala编译目录进行对比，找到缺失文件
