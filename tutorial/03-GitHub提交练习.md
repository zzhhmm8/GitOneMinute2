# 03：GitHub 提交练习

本包是练习项目，不是截图中原课程的官方仓库；没有提供原课程的 GitHub 地址，因此不能直接提交到原课程仓库。

## 方式 A：上传到自己的新仓库

先完成教程 02。在 GitHub 新建名为 GitOneMinute 的空仓库。由于本地已经包含 README、LICENSE 和 .gitignore，创建远程时不要再勾选生成这些文件，避免产生两套独立历史。

将下面地址中的 `YOUR_USERNAME` 改为实际用户名：

```bash
git remote add origin https://github.com/YOUR_USERNAME/GitOneMinute.git
git remote -v
git push -u origin main
```

首次推送按 Git 的提示完成身份验证。提交作者姓名和邮箱不等于登录；HTTPS 身份验证不能用 GitHub 账户密码代替凭据。

以后在 main 上提交新修改后执行 `git push` 即可上传。

## 方式 B：给原课程或他人仓库提交记录

这条流程是独立练习，不要在已经初始化的本项目目录里重复 clone。

1. 找到老师提供的真实课程仓库地址，在 GitHub 打开它并 Fork 到自己的账户。
2. 在另一目录克隆自己的 Fork，地址需替换为实际仓库地址：

```bash
git clone https://github.com/YOUR_USERNAME/GitOneMinute.git
cd GitOneMinute
git switch -c add-my-name
```

3. 按该仓库实际代码格式，给 src/main.cpp 新增自己的记录，构建并检查输出。
4. 提交并推送分支：

```bash
git diff
git add src/main.cpp
git commit -m "Add my learning record"
git push -u origin add-my-name
```

5. 在 GitHub 创建 Pull Request：目标选择原课程仓库的默认分支，来源选择你 Fork 中的 add-my-name 分支。写明新增了自己的学习记录，以及程序运行结果。

Fork 是服务器上的仓库副本，clone 是下载到本地，分支用于隔离修改，Pull Request 用于请求维护者审核合并。没有原仓库写权限时，不能直接向原仓库 push。

## 遇到冲突怎么办

在进行合并前先提交或妥善保存自己的工作。如果两个人都改了列表的同一位置，可能出现冲突。打开文件，找到 `<<<<<<<`、`=======`、`>>>>>>>` 标记，保留双方应有的记录，补好英文逗号，删除冲突标记并重新编译，再执行：

```bash
git add src/main.cpp
git commit
```

此处描述的是 merge 冲突；rebase 的继续命令不同。不要直接删除其他人的名字来消除冲突。
