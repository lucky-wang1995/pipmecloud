#pragma once

#if defined(Q_OS_WIN)

	int GetModuleFileName(void* Fun, char*& sFilePath)
	{
		HANDLE hDllhandle = GetModuleHandle("当前动态库名");//获取当前模块句柄
		if (hDllhandle == NULL)
		{
			MessageBox(NULL, "获取动态库句柄失败", "", MB_OK);
		}
		char buff[MAX_PATH];
		memset(buff, 0, MAX_PATH);
		GetModuleFileName((HMODULE)hDllhandle, buff, MAX_PATH);//获取当前模块句柄路径
	}


#else 

	int GetModuleFileName(void* Fun, char*& sFilePath)
	{
		int ret = -1;
		if ((g_prePath = getcwd(NULL, 0)) == NULL)    //此方法是获取程序运行当前路径，保存下来，以便最后再设置回来
		{
			perror("getcwd error");
		}
		else
		{
			//printf("PrePath: %s\n", g_prePath);
		}

		Dl_info dl_info;        //特定结构体
		if (dladdr(Fun, &dl_info))        //第二个参数就是获取的结果
		{
			ret = 0;
			sFilePath = strdup(dl_info.dli_fname);
			char* pName = strrchr(sFilePath, '/');    //找到绝对路径中最后一个"/"
			*pName = '\0';                            //舍弃掉最后“/”之后的文件名，只需要路径
		}

		return ret;
	}
#endif// Q_OS_WIN
