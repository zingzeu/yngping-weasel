#include "stdafx.h"
#include "Globals.h"

HINSTANCE g_hInst;

LONG g_cRefDll = -1;

CRITICAL_SECTION g_cs;

// {1B4A4B30-B810-4483-8CE6-A5FF82835999}
static const GUID c_clsidTextService = 
{ 0x1B4A4B30, 0xB810, 0x4483, { 0x8C, 0xE6, 0xA5, 0xFF, 0x82, 0x83, 0x59, 0x99 } };

// {661B35E7-4637-47F3-8E13-6CEA1E9C6E7E}
static const GUID c_guidProfile = 
{ 0x661B35E7, 0x4637, 0x47F3, { 0x8E, 0x13, 0x6C, 0xEA, 0x1E, 0x9C, 0x6E, 0x7E } };

// {341F9E3A-B8AD-499D-936C-48701E329FB2} TODO: change. This is weasel's.
static const GUID c_guidLangBarItemButton = 
{ 0x341f9e3a, 0xb8ad, 0x499d, { 0x93, 0x6c, 0x48, 0x70, 0x1e, 0x32, 0x9f, 0xb2 } };

#ifdef WEASEL_USING_OLDER_TSF_SDK

/* For Windows 8 */
const GUID GUID_TFCAT_TIPCAP_IMMERSIVESUPPORT =
{ 0x13A016DF, 0x560B, 0x46CD, { 0x94, 0x7A, 0x4C, 0x3A, 0xF1, 0xE0, 0xE3, 0x5D } };

const GUID GUID_TFCAT_TIPCAP_SYSTRAYSUPPORT =
{ 0x25504FB4, 0x7BAB, 0x4BC1, { 0x9C, 0x69, 0xCF, 0x81, 0x89, 0x0F, 0x0E, 0xF5 } };

#endif

const GUID GUID_LBI_INPUTMODE =
{ 0x2C77A81E, 0x41CC, 0x4178, { 0xA3, 0xA7, 0x5F, 0x8A, 0x98, 0x75, 0x68, 0xE6 } };

const GUID GUID_IME_MODE_PRESERVED_KEY =
{ 0x0bd899fc, 0xa8f7, 0x4b42, { 0xa9, 0x6d, 0xce, 0xc7, 0xc5, 0x0e, 0x0e, 0xae } };
