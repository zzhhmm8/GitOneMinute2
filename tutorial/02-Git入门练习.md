# 02：Git 入门练习

## 先理解三个位置

- 工作区：你正在编辑的文件。
- 暂存区：用 `git add` 选择准备提交的修改。
- 本地仓库：用 `git commit` 保存的历史记录。

`commit` 保存到本机，`push` 才会上传到远程仓库。

## 1. 准备 Git

从 Git 官方网站 https://git-scm.com/ 安装 Git。Windows 可使用 Git Bash，也可在安装完成后重新打开 PowerShell。

```bash
git --version
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

提交姓名和邮箱是历史记录的作者信息，不是 GitHub 登录凭据。邮箱可使用 GitHub 提供的隐私邮箱。`--global` 会影响此电脑上的其他仓库；只想配置当前项目时，在初始化后去掉 `--global`。

## 2. 初始化并保存起点

进入包含 README.md 的 GitOneMinute 文件夹后执行：

```bash
git init -b main
git status
git add .
git commit -m "Initial GitOneMinute project"
```

此时所有初始文件已经存入本地历史。`.gitignore` 会让构建产物不参与提交。

## 3. 创建自己的分支

```bash
git switch -c add-my-name
```

编辑 `src/main.cpp`，保留示例记录，新增自己的名字和学习时间，并重新运行程序。

## 4. 检查并提交

```bash
git diff
git add src/main.cpp
git diff --staged
git commit -m "Add my learning record"
git status
git log --oneline --graph --all
```

`git diff` 查看尚未暂存的改动；`git diff --staged` 查看即将提交的内容。提交后 `git status` 应显示工作区干净。

## 5. 合并回 main

```bash
git switch main
git merge add-my-name
git log --oneline --graph --all
```

这个练习通常会发生快进合并：main 直接移动到新提交。分支不是另一套永久复制的文件，它是指向提交的引用。

## 6. 练习撤销暂存

先给 README.md 添加一句练习说明，再执行：

```bash
git add README.md
git restore --staged README.md
git status
```

修改仍留在工作区，只是退出暂存区。若要保留说明，可以再次 add 并 commit。

确认不需要这段尚未提交的修改后，才使用 `git restore README.md`。这个命令会丢弃该文件未暂存的修改。

## 常用命令速查

| 命令 | 作用 |
| --- | --- |
| git status | 查看文件状态和当前分支 |
| git diff | 查看尚未暂存的修改 |
| git add 文件名 | 暂存指定文件 |
| git commit -m "说明" | 保存暂存区内容到历史 |
| git log --oneline | 简洁查看历史 |
| git switch 分支名 | 切换已有分支 |
| git switch -c 分支名 | 创建并切换分支 |
| git merge 分支名 | 把指定分支合并到当前分支 |
| git remote -v | 查看远程仓库地址 |
| git push | 推送本地提交 |

完成标准：程序打印自己的记录、历史中有初始提交和添加记录提交、能解释 add / commit / push 的区别。
