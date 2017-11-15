echo off
cls

mkdir BackupFolder

echo ******************************************************************************************************************
echo 
echo This is subject one testing out a batch file i have created
echo 
echo ******************************************************************************************************************
 
 robocopy/e "C:\Users\user\Documents\William files from memory card\College\test_1" "C:\Users\user\Documents\William files from memory card\College\BackupFolder"

 echo copy complete 

