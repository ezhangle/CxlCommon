#pragma warning(disable : 4996)
#pragma warning(disable : 4100)


#include <gtest/gtest.h>
#include <AMDTOSWrappers/Include/osFile.h>

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