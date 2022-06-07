###
 # @Author: rooterShip
 # @Date: 2022-06-05 13:44:31
 # @LastEditors: Titc 1240104681@qq.com
 # @LastEditTime: 2022-06-06 00:22:03
### 


# 管理员界面
function adminInterface(){
    echo "当前角色为管理员"
    echo "[1] 创建新用户"
    echo "[2] 删除旧用户"
    echo "[3] 解锁用户"
    echo "[4] 权限管理"
    echo "[5] 退出"
}

# 管理员创建新用户功能
function adminAddUser(){
    echo "一旦用户创建成功，则可以登录到该系统中来"

    # 判断新用户名字是否为空
    read -p "请输入要添加的用户名:" addUsername
    # -P 提示
    while [ ! -n "${addUsername}" ]
    #！-n = -z 去掉双引号 
    do
        echo "用户名不能为空！"
        read -p "请输入要添加的用户名:" addUsername
    done

    # 判断新创建的用户是否存在
    if [ -d "users/${addUsername}" ]
    then
        echo "用户已经存在！"
    # 实现增加功能
    else
        createTime="`date +%Y%m%d`"
        read -s -p "请输入用户密码：" addPassword
        read -p "请输入用户身份（commonAdmin/user）" Identity
        mkdir -p users/${addUsername} && touch users/${addUsername}/userInfo.txt 
        #mkdir 创建文件夹  touch  创建文件
        echo "${addUsername},${addPassword},${Identity},open,${createTime}" >> users/${addUsername}/userInfo.txt
        #>> 追加
        echo "创建成功"
    fi
}

# 管理员删除旧用户功能
function adminDelUser(){
    echo "一旦用户被删除，则无法登录到该系统中来!"
    read -p "请输入想要删除的用户的用户名：" delUsername

    # 判空
    while [ ! -n "${delUsername}" ]
    do
        echo "用户名不能为空！"
        read -p "请输入想要删除的用户的用户名：" delUsername
    done

    # 判断是否不存在
    if [ ! -d "users/${delUsername}" ]
    then
        echo "不能删除不存在的用户！"
    # 实现删除功能
    else
        rm -rf users/${delUsername}
    # rm -rf 递归删除 所有子文件夹也被删除
        echo "删除成功"
    fi
}

# 管理员解锁功能
function adminOpen(){
    echo "用于解锁，验证三次失败的普通用户"
    read -p "请输入想要被解锁的用户的用户名：" openUsername

    # 判空
    while [ ! -n "${openUsername}" ]
    do
        echo "用户名不能为空！"
        read -p "请输入想要被解锁的用户的用户名：" openUsername
    done

    # 判断存在
    if [ ! -d "users/${openUsername}" ]
    then
        echo "该用户不存在"
    #实现解锁功能 
    else
        sed -i 's/lock/open/' users/${openUsername}/userInfo.txt
        # -i：用 sed 的修改结果直接修改读取数据的文件，而不是由屏幕输出动作   对字符串进行替换
        echo "解锁成功"
    fi
}

# 管理员更改用户权限功能
function adminModifyIdentity(){
    echo "分配权限，将普通用户设置为管理员，管理员设置为普通用户，其中admin用户不得更改"
    read -p "请输入想要被更改权限用户的用户名：" modifyUsername

    # 判空
    while [ ! -n "${modifyUsername}" ]
    do
        echo "用户名不能为空！"
        read -p "请输入想要被更改权限用户的用户名：" modifyUsername
    done

    # 判存在
    if [ ! -d "users/${modifyUsername}" ]
    then
        echo "该用户不存在"
    # 实现更改用户权限功能
    else
        identity=$( cat users/${modifyUsername}/userInfo.txt| awk -F "," '{ printf $3 }' )
        # 用顿号    awk 是特殊命令
        if [ "${identity}" == "user" ]
        then
            sed -i 's/user/commonAdmin/' users/${modifyUsername}/userInfo.txt
            echo "更改成功"
        fi

        if [ "${modifyUsername}" == "admin" ]
        then
            echo "admin用户不得更改"
        else
            if [ "${identity}" == "commonAdmin" ]
            then
                sed -i 's/commonAdmin/user/' users/${modifyUsername}/userInfo.txt
                echo "更改成功"
            fi
        fi
    fi
}
# 管理员退出功能
function adminExit(){
    exit
    echo "您已经成功退出"
}



# 普通用户界面
function userInterface(){
    echo "当前角色为普通用户"
    echo "[1] 新建文本文件"
    echo "[2] 新建目录"
    echo "[3] 统计文档信息"
    echo "[4] 权限查看"
    echo "[5] 退出"
}

# 普通用户新建文本文件功能
function userAddTxt(){
    read -p "请输入新建文本文件的文件名：" fileName

    # 判空
    while [ ! -n "${fileName}" ]
    do
        echo "文件名不能为空"
        read -p "请输入新建文本文件的文件名：" fileName
    done
    
    # 判存在
    if [ -f "users/${username}/${fileName}" ]
    then
        echo "文件已经存在"
    else
        touch users/${username}/${fileName}
        echo "文件成功创建"
    fi
}

# 普通用户新建目录功能
function userAddDir(){
    read -p "请输入新建目录的目录名：" dirName

    # 判空
    while [ ! -n "${dirName}" ]
    do
        echo "目录名不能为空"
        read -p "请输入新建目录的目录名：" dirName
    done

    # 判存在
    if [ -d "users/${username}/${dirName}" ]
    then
        echo "目录已经存在"
    else
        mkdir users/${username}/${dirName}
        echo "目录已经创建"
    fi
}

# 普通用户统计文档信息功能
function userCheckInfo(){
    read -p "请输入要查看文件的文件名：" fileName

    # 判空
    while [ ! -n "${fileName}" ]
    do
        echo "文件名不能为空"
        read -p "请输入要查看文件的文件名：" fileName
    done

    # 判存在
    if [ -f "users/${username}/${fileName}" ]
    # -f 判断后面文件是否存在 -d 判断后面的文件夹是否存在
    then
        lineNum=`cat "users/${username}/${fileName}" | wc -l `
        wordNum=`cat "users/${username}/${fileName}" | wc -w `
        charNum=`cat "users/${username}/${fileName}" | wc -c `
        echo "行数为：" $lineNum
        echo "单词数为：" $wordNum 
        echo "字符数为：" $charNum
    else
        echo "目录不存在！"
    fi
}

# 普通用户权限查看功能
function userCheckPermission(){
    read -p "请输入要查看文件的文件名：" fileName

    # 判空
    while [ ! -n "${fileName}" ]
    do
        echo "文件名不能为空"
        read -p "请输入要查看文件的文件名：" fileName
    done

    # 判存在
    if [ -f "users/${username}/${fileName}" ]
    then
        if [ -r "users/${username}/${fileName}" ]
        # -r 可读
        then
            filePermission="Readable"
        fi

        if [ -w "users/${username}/${fileName}" ]
        #-w 可写
        then
            filePermission="Writeable"
        fi

        if [ -x "users/${username}/${fileName}" ]
        # -x 可执行
        then
            filePermission="Executable"
        fi

        if [ -r "users/${username}/${fileName}" ] && [ -w "users/${username}/${fileName}" ]
        then
            filePermission="Readable & Writeable"
        fi

        if [ -r "users/${username}/${fileName}" ] && [ -x "users/${username}/${fileName}" ]
        then
            filePermission="Readable & Executable"
        fi

        if [ -w "users/${username}/${fileName}" ] && [ -x "users/${username}/${fileName}" ]
        then
            filePermission="Writeable & Executable"
        fi

        if [ -r "users/${username}/${fileName}" ] && [ -w "users/${username}/${fileName}" ] && [ -x "users/${username}/${fileName}" ]
        then
            filePermission="Readable & Writeable & Executable"
        fi
        echo ${filePermission}
    else
        echo "文件不存在"
    fi
}

# 普通用户退出功能
function userExit(){
    exit
    echo "您已经成功退出"
}



# 管理员界面连接具体功能
function adminOperate(){
    # 调用管理员界面函数
    adminInterface
    read -p "输入功能数字选项" opNumber
    case $opNumber in
    1) adminAddUser;;
    2) adminDelUser;;
    3) adminOpen;;
    4) adminModifyIdentity;;
    5) adminExit;;
    esac
} 


# 普通用户界面连接具体功能
function userOperate(){
    # 调用普通用户界面
    userInterface
    read -p "输入功能数字选项" opNumber
    case $opNumber in
    1) userAddTxt;;
    2) userAddDir;;
    3) userCheckInfo;;
    4) userCheckPermission;;
    5) userExit;;
    esac
}


# 主命令
read -p "请输入用户名:" username

# 判断用户输入的username是否为空
while [ ! -n "${username}" ]
do
    echo "用户名不能为空！"
    read -p "请输入用户名:" username
done

# admin账户直通
if [ "${username}" == "admin" ]
then
    read -s -p "请输入密码：" adminPassword
    if [ "${adminPassword}" == "123456" ]
    then
        adminOperate
    else
        echo  "密码错误！"
    fi
else
    # 判断用户是否存在
    if [ ! -d "users/${username}" ]
    then
        echo "用户不存在！"
    else
        # 将用户信息放进一个数组中
        for i in {0..4}
        do
            info[i]=$( cat users/${username}/userInfo.txt| awk -F "," -va=$[$i+1] '{ printf $a }' )
        done

        # 判断用户当前状态（open/lock)
        if [ "${info[3]}" == "lock" ]
        then
            echo "该用户已被锁定，请联系管理员！！！"
            exit
        else
            read -s -p "请输入密码：" password
            flag=1
            while [ $flag -le 3 ]&&[ "${password}" != "${info[1]}" ]
            #-le 小于
            do
                if [ $flag -eq 3 ]
                #-eq 大于
                then
                    if [ "${info[2]}" == "commonAdmin" ]
                    then
                        echo "已锁定"
                        sed -i 's/open/lock/' users/${username}/userInfo.txt
                        chmod -777 login.sh
                        exit
                    else
                        echo "该用户已被锁定，请联系管理员！！！"
                        sed -i 's/open/lock/' users/${username}/userInfo.txt
                        exit
                    fi
                else
                    echo "密码错误！"
                    read -s -p "请输入密码：" adminPassword
                    let flag++
                fi
            done

            # 进入角色功能界面
            if [ "${info[2]}" == "user" ]
            then
                userOperate
            else
                adminOperate
            fi
        fi
    fi
fi
    
