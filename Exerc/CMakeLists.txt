# 查找所有源文件
# 保存名称 到 MATH_LIB 里面


aux_source_directory(. QT_SRC)
# 生成MATH_LIB链接库
add_library(Exer SHARED ${QT_SRC})
