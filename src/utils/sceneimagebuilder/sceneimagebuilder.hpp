//= SceneImageBuilder -> Written by Unusuario2, https://github.com/Unusuario2  =//
//
// Purpose: 
//
// License:
//        MIT License
//
//        Copyright (c) 2025 [un usuario], https://github.com/Unusuario2
//
//        Permission is hereby granted, free of charge, to any person obtaining a copy
//        of this software and associated documentation files (the "Software"), to deal
//        in the Software without restriction, including without limitation the rights
//        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//        copies of the Software, and to permit persons to whom the Software is
//        furnished to do so, subject to the following conditions:
//
//        The above copyright notice and this permission notice shall be included in all
//        copies or substantial portions of the Software.
//
//        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//        OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//        SOFTWARE.
//
//==============================================================================//
#ifndef SCENEIMAGEBUILDER_H
#define SCENEIMAGEBUILDER_H

#ifdef _WIN32
#pragma once
#endif // _WIN32

#include "appframework/tier3app.h"
#include "sceneimage.h"
#include "choreoevent.h"
#include "sceneimage.cpp"


#define SCENESRC_DIR	"scenes"
#define SCENEIMAGE_FILE "scenes.image"


class CSceneImageBuilderApp : public CTier3SteamApp, public ISceneImage
{
private:
	typedef CTier3SteamApp BaseClass;

private:
	CSceneImage m_SceneImage;
	bool m_bPause = false;
	bool m_bQuiet = false;
	bool m_bLog = false;

private:
	void ParseCommandline();
	void HitKeyToContinue();
	void PrintUsage();
	void PrintHeader();
	virtual bool SetupSearchPaths();

public:
	virtual bool CreateSceneImageFile(CUtlBuffer& targetBuffer, char const* pchModPath, bool bLittleEndian, bool bQuiet, ISceneCompileStatus* Status) override;
	virtual bool PreInit();
	virtual void PostShutdown();
	virtual bool Create();
	virtual void Destroy();
	virtual int	 Main();
    virtual void SceneBuild();
};


#endif // SCENEIMAGEBUILDER_H