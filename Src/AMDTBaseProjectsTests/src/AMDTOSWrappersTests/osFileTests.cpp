#pragma warning(disable : 4996)
#pragma warning(disable : 4100)


#include <gtest/gtest.h>
#include <AMDTOSWrappers/Include/osFile.h>

<<<<<<< HEAD
TEST(osFileIsExecutable, IsExecutableOk)
{
    gtString filePathStr = LR"(c:\temp\nosuchfile.txt)";
    osFilePath filePath = filePathStr;
    osFile myFile(filePath);
    EXPECT_FALSE(myFile.IsExecutable());

    wchar_t buf[MAX_PATH] = {};
    EXPECT_NE(0, GetModuleFileName(nullptr, buf, MAX_PATH));
    filePathStr = buf;
    filePath = filePathStr;
    myFile.setPath(filePath);
    EXPECT_TRUE(myFile.IsExecutable());

}
=======
TEST(osFileIsExecutable, IsExecutableCheck)
{
    gtString path = LR"(c:\temp\NoSuchFile.txt)";
    osFilePath filePath = path;
    osFile myFile(filePath);
    bool res = myFile.IsExecutable();
    EXPECT_FALSE(res);
    
    wchar_t currentProcessPathBuf[MAX_PATH] = {};
    EXPECT_NE(0, GetModuleFileName(nullptr, currentProcessPathBuf, MAX_PATH));
    path = currentProcessPathBuf;
    filePath = path;
    myFile.setPath(filePath);
    res = myFile.IsExecutable();
    EXPECT_TRUE(res);

}
>>>>>>> refs/heads/Common
