/*
            This file is part of: 
                NoahFrame
            https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2021 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang
   
   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#include "Tutorial4Plugin.h"
#include "HelloWorld4Module.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, Tutorial4Plugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, Tutorial4Plugin)
};

#endif
//////////////////////////////////////////////////////////////////////////

const int Tutorial4Plugin::GetPluginVersion()
{
    return 0;
}

const std::string Tutorial4Plugin::GetPluginName()
{
    return "Tutorial4";// GET_CLASS_NAME(Tutorial4Plugin);
}

void Tutorial4Plugin::Install()
{

    REGISTER_MODULE(pPluginManager, NFIHelloWorld4Module, NFHelloWorld4Module)

}

void Tutorial4Plugin::Uninstall()
{
    UNREGISTER_MODULE(pPluginManager, NFIHelloWorld4Module, NFHelloWorld4Module)
}
