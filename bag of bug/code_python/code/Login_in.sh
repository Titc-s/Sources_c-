#管理员操作界面
function ad_Interface()
{
    echo "您是尊贵的管理员"
    echo "[1] 创建新用户"
    echo "[2] 删除旧用户"
    echo "[3] 解锁用户"
    echo "[4] 权限管理"
    echo "[5] 退出"
}
# 管理员功能实现
function ad_Op()
{
    #调用函数
    ad_Interface
    read -p "选择功能" op_Num
    case $op_Num in
    1) ad_Add;;
    2) ad_Del;;
    3) ad_Open;;
    4) ad_Modify_Id;;
    5) ad_Exit;;
    esac
}

#以下是管理员操作函数：
# 创建用户
function ad_Add()
{
    echo "您正在创建用户"
    echo "一旦用户创建成功，则可以登录到该系统中来"

    #判断输入的用户名是否为空
    read -p "请新建用户名:"add_Name
    while [-z $add_Name]
    do
      read -p  "您输入用户名为空！请重新输入:" add_Name
    done

    #判断输入的用户名是否已经存在
    if [ -d "users/${add_Name}" ]
    then 
    echo "用户已经存在，请返回重试"

    else
      create_Time = "`date +%Y%m%d`"
      read -s -p "输入密码:"add_Pw
      #-s 隐藏输入的数字
      read -p "请输入用户权限(用户(user)/管理员(admin_n))" Id
      mkdir -p users/${add_Name} && touch users/${add_Name}/user_Info.txt
      echo "${add_Name}、${add_Pw}、${Id}、unlocked、${create_Time}" >> user/${add_Name}/userInfo.txt

     echo "创建成功！"
fi
}

# 删除用户
function ad_Del()
{
    echo "一旦用户被删除，则无法登录到该系统中来!"
    read -p "请输入要删除的用户名：" del_Name

    #判断为空
    while [ -z $del_Name ]
    do
      read -p  "您输入用户名为空！请重新输入:" del_Name
    done

    #判断输入是否存在

      if [ -d "users/${del_Name}" ]
    then 
    echo "用户不存在或已经被删除"
    # 删除实现
    else
    rm -rf users/${del_Name}
    echo "删除成功了内"
fi
}

#解锁
function ad_Open()
{
 echo "用于解锁，验证三次失败的普通用户"
 read -p "请输入已被锁定的账户" op_Name

 #判断为空
   while [ -z $op_Name ]
    do
      read -p  "您输入用户名为空！请重新输入:" op_Name
    done
  #判断是否存在账户
     if [ -d "users/${op_Name}" ]
    then 
    echo "用户不存在,不能给你解锁"
    else    
        state =$( cat users/${op_Name}/user_Info| awk -f "、" '{printf $4 }')
        if ["${state}" == "unlocked" ];then
        echo "未被上锁，该用户可以直接登录"
        else
        sed -i 's/lock/unlocked/' users/${op_Name}/user_Info.txt
        echo "解锁成功，现在该账号可以正常登录了！"
        fi
    fi
}

#管理员更改用户权限
function ad_Modify_Id()
{
     echo "分配权限，将普通用户设置为管理员，管理员设置为普通用户，其中admin用户不得更改"
     read -p "请输入用户名以更改用户权限" modify_Name

    #判断为空
    while [ -z $modify_Name ]
    do
      read -p  "您输入用户名为空！请重新输入:" modify_Name
    done

    #存在性
    if [ ! -d "users/${modify_Name}" ]
    then
        echo "该用户不存在,无法修改权限"
    else 
      Identity = $( cat users/${modify_Name}/user_Info.txt| awk -F "、" '{ printf $3 }' )
      # 读取权限信息
     if ["${modify_Name}"=="admin"]
      then 
      echo "admin用户不得更改"
      fi

      if [ "${Identity}" == "user" ]
      then 
      sed -i 's/user/admin_n' users/${modify_Name}/user_Info.txt
      echo "修改成功，该账户现在权限是：管理员"
      fi

      if [ "${Identity}" == "admin_n" ]
      then 
      sed -i 's/admin_n/user' users/${modify_Name}/user_Info.txt
      echo "修改成功，该账户现在权限是：普通用户"
      fi
      fi
}

function ad_Exit()
{
    exit
    echo "退出登录"
}
# 普通用户
function user_Interface()
{
    echo "当前角色为普通用户"
    echo "[1] 新建文本文件"
    echo "[2] 新建目录"
    echo "[3] 统计文档信息"
    echo "[4] 权限查看"
    echo "[5] 退出"
}
# 普通用户功能接口
function user_Op()
{
  user_Interface
  read -p "选择功能" op_Num
    case $op_Num in
    1) user_Addtext;;
    2) user_AddCatelogue;;
    3) user_Statistical;;
    4) user_ViewPermission;;
    5) ad_Exit;;
    esac
}

#新建文本
function user_Addtext()
{
    read -p "请命名新建文本文件：" text_Name

    #是否为空
    while [ -z $text_Name ]
    do
        read -p "无法创建名称为空的文本文件，请重新输入" text_Name
    done
    if [ -f "users/${username}/${text_Name}" ]
    then
    echo "文件已存在，创建失败"
    else
     touch users/${username}/${text_Name}
     echo "文本文件${text_Name}创建成功"
     fi
}

function user_AddCatelogue()
{
    read -p "请明明新建目录名：" Cate_Name

    #空空
    while [ -z $Cate_Name ]
     do
        read -p "无法创建名称为空的目录，请重新输入" Cate_Name
    done

    if [ -d "users/${username}/${Cate_Name}" ]
    then
    echo "目录已经存在，创建失败"
    else
    mkdir users/${username}/${Cate_Name}
    echo "目录创建成功"
    fi
}

function user_Statistical()
{
     read -p "请输入要统计的文件名：" text_Name

     #判空
     while [ -z $text_Name ]
    do
        read -p "文件为空，无法查看，请重新输入" text_Name
    done
      if [ -f "users/${username}/${text_Name}" ]
      # -f 判断文件是否存在， -d判断文件夹是否存在
    then
        line_Num = `cat "users/${username}/${text_Name}" | wc -l `
        word_Num = `cat "users/${username}/${text_Name}" | wc -w `
        char_Num = `cat "users/${username}/${text_Name}" | wc -m `
        # wc (word count) -c 统计字节数、-l统计行数、-m 统计字符数,-w 统计字数。-L 打印最长行的长度
        echo "行数为：" $line_Num
        echo "单词数为："$word_Num
        echo "字符数为："$char_Num
    else
    echo "该文件不存在，无法统计"
    fi
}

#查看权限功能
function user_ViewPermission()
{
   read -p "请输入要查看权限的文件名：" text_Name
   #空
   while [ -z $text_Name ]
    do
        read -p "文件为空，无法查看，请重新输入" text_Name
    done
    # -r 可读 -w 可写 -x 可执行
      if [ ! -f "users/${username}/${text_Name}" ]
        then
      echo "文件不存在，无法查看"
      else
      str[0] = "文件${text_Name}权限为"
      if [ -r "users/${username}/${text_Name}" ];then
      str[1] = "Readable"
      fi
      if [ -w "users/${username}/${text_Name}" ];then
      str[3] = "Writeable"
      fi
      if [ -x "users/${username}/${text_Name}" ];then
      str[5] = "Executable"
      fi
       
       #判断数组长度，以添加&

      if [ "${#str[@]}" -eq "3" ];then
      str[2] = "&";
      elif [ "${#str[@]}" -eq "5" ];then
      str[4] = "&";
      fi
        echo ${str[@]}
    fi
}

# 主界面

read -p "请输入用户名：" username

#空：
 while [ -z $username ]
    do
        read -p "用户名为空，请重新输入" username
    done

# 系统预设管理员：
if [ "${username}" == "admin" ]
then
    read -s -p "请输入密码：" ad_Password
    if [ "${adminPassword}" == "123456" ]
    then
        ad_Interface
    else
        echo  "密码错误！"
    fi
else
 if [ ! -d "users/${username}"]
 then 
  echo "用户不存在"
else
   #数组记录用户信息
   for i in {0..4}
   do 
      user_Infoo[i]=$( cat users/${username}/userInfo.txt| awk -F "、" -va=$[$i+1] '{ printf $a }')
     done

    if [ "${user_Infoo[3]}" == "lock" ]
    then
    echo "***用户已被锁定，请联系管理员！！！"
    exit
else
    read -s -p "输入密码：" password
    put_time = 1
    while [ $put_time -le 3 ]&&[ "${password}" != "${user_Infoo[1]}" ]
    do 
      if [ $put_time -eq 3 ]
    then
       if [ "${user_Infoo[2]}" == "admin_n" ]
       then
       echo "已锁定！！！"
       sed -i 's/unlocked/lock' users/${username}/user_Info.txt
       chmod -777 log_in.sh
       exit
    else 
     echo "***用户已被锁定，请联系管理员！！！"
     sed -i 's/unlocked/lock' users/${username}/user_Info.txt
      exit
      fi
    else 
     echo "密码或用户名错误!"
     read -s -p "输入密码：" password 
     let put_time++
     fi
     done


     if [ "${user_Infoo[2]}" == "user" ]
     then 
     user_Interface
     else 
    ad_Interface
    fi
    fi
    fi
    fi


