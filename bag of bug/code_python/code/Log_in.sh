#!/bin/bash
###############################
## @author:潘孝飞            ##
## 1. 输入变量                  
##      username  
##      password
## 2. 用户信息文件
##      ./Users/username/userInfo.txt
## 3.
##
##
##############################

#---------------------------公用function-----------------------------#
# 输入exit退出程序
function isExit()
{
    if [ "$1" == "exit" ];then
    echo "系统退出"
    exit
    fi
}

#---------------------------管理员function---------------------------#
# 管理员页面
function interface_admin()
{
    sleep 2s
    clear
    echo "登录成功！！！"
    echo "当前角色为管理员"
    echo "[1] 创建新用户"
    echo "[2] 删除旧用户"
    echo "[3] 解锁用户"
    echo "[4] 权限管理"
    echo "[5] 退出"
}

# 管理员增加用户
function add_Users()
{
    echo "一旦用户创建成功，则可以登录到该系统中来"
    read -p "please enter username：" new_username && isExit ${new_username}
    while [ -z $new_username ]
    do 
        echo "input is empty!"
        read -t 20 -p "please reenter username in 20 seconds: " new_username && isExit ${new_username}
    done
    
    # 判断用户名是否存在
    if [ -d "Users/${new_username}" ];then
        echo "user already exists！"
    else
        mkdir -p Users/${new_username} && touch Users/${new_username}/Info.txt
        current_time="`date +%F` `date +%T`"
        read -t 20 -p "please enter user's password: " new_password
        read -t 20 -p "please enter user's authority: (user/admin) (default is user)" new_authority
        echo "${new_username};${new_password};${new_authority:-user};unlock;${current_time}" >> Users/${new_username}/Info.txt
        echo "创建成功！"
    fi
}

# 管理员删除用户
function delete_Users()
{
    echo "一旦用户被删除，则无法登录到该系统中来"
    read -p "please enter username：" delete_username && isExit ${delete_username}
    while [ -z $delete_username ]
    do 
        echo "input is empty!"
        read -t 20 -p "please reenter username in 20 seconds: " delete_username && isExit ${delete_username}
    done

    # 判断用户名是否存在
    if [ ! -d "Users/${delete_username}" ];then
        echo "user does not exists！"
    else
        rm -rf Users/${delete_username}
        echo "Finish!"
    fi
}

# 管理员解锁用户
function unlock_Users()
{
    echo "用于解锁，验证三次失败的普通用户"
    read -p "please enter username：" unlock_username && isExit ${unlock_username}
    while [ -z $unlock_username ]
    do 
        echo "input is empty!"
        read -t 20 -p "please reenter username in 20 seconds: " unlock_username && isExit ${unlock_username}
    done

    # 判断用户名是否存在
    if [ ! -d "Users/${unlock_username}" ];then
        echo "user does not exists！"
    else
        state=$( cat Users/${unlock_username}/Info.txt| awk -F ";" '{ printf $4 }' )
        if [ "${state}" == "unlock" ];then
            echo "铁子他没被锁"
        else
            sed -i 's/lock/unlock/' Users/${unlock_username}/Info.txt
            echo "unlock successfully!"
        fi
    fi
}

# 管理员更改用户权限
function authority_Users()
{
    echo "分配权限，将普通用户设置为管理员，管理员设置为普通用户，其中admin用户不得更改"
    read -p "please enter username：" authority_username && isExit ${authority_username}
    while [ -z $authority_username ]
    do 
        echo "input is empty!"
        read -t 20 -p "please reenter username in 20 seconds: " authority_username && isExit ${authority_username}
    done

    # 判断用户名是否存在
    if [ ! -d "Users/${authority_username}" ];then
        echo "user does not exists！"
    else
        authority=$( cat Users/${authority_username}/Info.txt| awk -F ";" '{ printf $3 }' )
        if [ "${authority}" == "user" ];then
            read -p "please determine whether to upgrade power [y/n(default)]: " option
            if [ "${option:-n}" == "y" ];then
                sed -i 's/user/admin' Users/${authority_username}/Info.txt
                echo "upgrade successfully!"
            else
                echo "权限不变"
            fi
        else
            if [ "${authority_username}" == "admin" ];then
                echo "admin can't be revoked!"
            else
                read -p "please determine whether to revoke power [y/n(default)]: " option
                if [ "${option:-n}" == "y" ];then
                    sed -i 's/admin/user/' Users/${authority_username}/Info.txt
                    echo "revoke successfully!"
                else
                    echo "权限不变"
                fi
            fi
        fi
    fi
}

#---------------------------用户function-----------------------------#
# 普通用户页面
function interface_user()
{
    sleep 1s
    clear
    echo "登录成功！！！"
    echo "当前角色为普通用户"
    echo "[1] 新建文本文件"
    echo "[2] 新建目录"
    echo "[3] 统计文档信息"
    echo "[4] 权限查看"
    echo "[5] 退出"
}

add_File()
{
    read -p "please enter a filename:" filename && isExit ${filename}

    while [ -z $filename ]
    do 
        echo "filename is empty!"
        read -t 20 -p "please reenter filename in 20 seconds: " filename && isExit ${filename}
    done

    if [ -f "Users/${username}/${filename}" ];then
        echo "file already exists!"
    else
        touch Users/${username}/${filename}
        echo "create file ${filename} successfully!"
    fi
}

add_Dir()
{
    read -p "please enter a directory:" dirname && isExit ${dirname}
    while [ -z $dirname ]
    do 
        echo "dirname is empty!"
        read -t 20 -p "please reenter dirname in 20 seconds: " dirname && isExit ${dirname}
    done

    if [ -d "Users/${username}/${dirname}" ];then
        echo "directory already exists!"
    else
        touch Users/${username}/${dirname}
        echo "create directory ${dirname} successfully!"
    fi
}

stats_info()
{
    read -p "please enter a filename:" filename && isExit ${filename}
    while [ -z $filename ]
    do 
        echo "filename is empty!"
        read -t 20 -p "please reenter filename in 20 seconds: " filename && isExit ${filename}
    done
    
    if [ ! -f "Users/${username}/${filename}" ];then
        echo "file does not exist!"
    else
        line_num=`cat "Users/${username}/${filename}" | wc -l `
        word_num=`cat "Users/${username}/${filename}" |wc -w `
        character_num=`cat "Users/${username}/${filename}" |wc -c`
        echo "行数："$line_num
        echo "单词数；"$word_num
        echo "字符数："$character_num
        sleep 10s
    fi
}

view_file_permission()
{
    read -p "please enter a filename:" filename && isExit ${filename}

    while [ -z $filename ]
    do 
        echo "filename is empty!"
        read -t 20 -p "please reenter filename in 20 seconds: " filename && isExit ${filename}
    done

    str[0]="the file ${filename}'s permission is " 
    if [ ! -f "Users/${username}/${filename}" ];then
        echo "file does not exist!"
    else
        if [ -r "Users/${username}/${filename}" ];then
            str[1]="Readable"
        fi

        if [ -w "Users/${username}/${filename}" ];then
            str[3]="Writeable"
        fi

        if [ -x "Users/${username}/${filename}" ];then
            str[5]="Executable"
        fi

        if [ "${#str[@]}" -eq "3" ];then
            str[2]="&"
        elif [ "${#str[@]}" -eq "5" ];then
            str[4]="&"                                   
        fi
            echo ${str[@]}
    fi
}
#---------------------------聚合function-----------------------------#
function choice_admin()
{
    interface_admin
    read -p "please choose function number: " choice && isExit ${choice}
    while [ $choice -ne 5 ]
    do
        case $choice in
        1)
            add_Users
        ;;
        2)
            delete_Users
        ;;
        3)
            unlock_Users
        ;;
        4)
            authority_Users
        ;;
        5)
            echo "退出登录"
            exit
        ;;
        *)
            interface_admin && read -p "please choose function number: " choice && isExit ${choice} 
        ;;
        esac
        interface_admin && read -p "please choose function number: " choice && isExit ${choice}
    done
}

function choice_user()
{
    interface_user
    read -p "please choose function number: " choice && isExit ${choice}
    while [ $choice -ne 5 ]
    do
        case $choice in
        1)
            add_File
        ;;
        2)
            add_Dir
        ;;
        3)
            stats_info
        ;;
        4)
            view_file_permission
        ;;
        5)
            echo "退出登录"
            exit
        ;;
        *)
            interface_user && read -p "please choose function number: " choice && isExit ${choice} 
        ;;
        esac
        interface_user && read -p "please choose function number: " choice && isExit ${choice}
    done
}

#-----------------------------主命令--------------------------------#
# 读取用户名
read -t 20 -p "please enter username in 20 seconds: " username && isExit ${username}

# 判断用户名是否为空
while [ -z $username ]
do 
    echo "username is empty!"
    read -t 20 -p "please reenter username in 20 seconds: " username && isExit ${username}
done

# 判断用户名是否存在
if [ ! -d "Users/${username}" ];then
    echo "user does not exist!"
else
    # 加载用户信息
    for i in {0..4};
    do
        userinfo[i]=$( cat Users/${username}/Info.txt| awk -F ";" -va=$[$i+1] '{ printf $a }' )
    done

    # 判断用户是否被锁定
    if [ "${userinfo[3]}" == "lock" ];then
        echo "***用户已被锁定，请联系管理员！！！"
        exit
    else
        # 判断密码
        read -t 20 -sp"please enter password in 20 seconds: " password && printf "\n"
        i=1
        while [ "$password" != "${userinfo[1]}" ]&&[ $i -le 3 ]
        do
            if [ $i -eq 3 ];then
                if [ "${userinfo[2]}" == "admin" ];then
                    echo "已锁定！！！"
                    chmod -777 Log_in.sh
                    sed -i 's/unlock/lock/' Users/${username}/Info.txt
                    exit
                else
                    echo "***用户已被锁定，请联系管理员！！！"
                    sed -i 's/unlock/lock/' Users/${username}/Info.txt
                    exit
                fi
            else
                echo "密码错误!"
                read -t 20 -sp"please reenter password in 20 seconds: " password && printf "\n"
                let i++
            fi
        done

        # 进入功能界面
        if [ "${userinfo[2]}" == "admin" ];then
            choice_admin
        else
            choice_user
        fi
    fi
fi