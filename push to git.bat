@echo off
@echo.
@echo Automated Git Commited created by: Salmoncatt
@echo.
@echo.

git config --global user.name "salmoncatt"
git config --global user.email "salmoncattyt@gmail.com"
git config --local core.autocrlf false

@echo set username to: salmoncatt
@echo set email to: salmoncattyt@gmail.com
@echo set CRLF to false
@echo.
@echo.

git add .
git status

set /p CommitMsg="Enter Commit Message: "

git commit -m "%CommitMsg%"
git push

pause