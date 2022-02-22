#!/bin/bash 

#程序说明：
#descirb:run exec file and redirect to out.txt
#crearted at:2021.03.25 coast

#指定环境变量
#PATH=          #本脚本不执行外部命令，便不指定工作目录，采用默认
#LANG=          #本脚本采用默认
#read -p "请输入递归目录名:" dirName
#export dirName  #自定义变量转为临时环境变量，子shell可用

#主程序部分：
#
#function recurDir(){
##echo $1
#for fileName in $(ls "$1") 
#do
##echo $fileName
#
#    if [ -f "$1/${fileName}" ];then #=~ 判断是否包含正则表达式字串，必须与[[]]一起使用
#         if [[ ${fileName} =~ \.(cpp|c|h|txt) ]];then #注意条件表达与两个中括号之间的空格;
#                                            #=～两边的空格;!(取非)两边的空格,也可!()
#                                            
#            if [[ ! $(file "$1/${fileName}") =~ UTF-8 ]] && \
#               [[ $(file "$1/${fileName}") =~ ISO-8859 ]];then
#
#             echo $(file "$1/${fileName}")
#            iconv -f gbk -t utf8 "$1/${fileName}" -o "$1/${fileName}.utf8"
#	     mv "$1/${fileName}.utf8" "$1/${fileName}"
#	 
#              echo $(file "$1/${fileName}")
#            fi
#
#         fi
#
#    elif [ -d "$1/${fileName}" ];then
#
#        dirName=$1/${fileName}
#        recurDir ${dirName}
#
#    else 
#
#      echo "$fileName can't to be iconv!"
#
#
#    fi
#done
#
#}
#
#
##echo "$1"
#recurDir $1

#情况文件。true命令
true >./out.txt

for i in OFF ON
do
    for j in 0 1
    do
       echo "#################">>out.txt
       echo "USE_NONRVO = ${i}">>out.txt
       echo "USE_SWITCH = ${j}">>out.txt
       echo "-----------------">>out.txt
       cd ../build
       cmake -D USE_NONRVO=${i} -D USE_SWITCH=${j} ../
       make
       make install 
       cd ../bin
       ./mytest >> out.txt 2>&1
       echo "----------------"
    done
done

