#pragma once
#include "ui/WeaselUI.h"
#include "ipc/WeaselIPC.h"
#include "third_party/system_tray/SystemTraySDK.h"

#define	WM_WEASEL_TRAY_NOTIFY (WEASEL_IPC_LAST_COMMAND + 100)


class WeaselTrayIcon : public CSystemTray
{
public:
	enum WeaselTrayMode {
		INITIAL, ZHUNG, ASCII, DISABLED,
	};

	WeaselTrayIcon(weasel::UI &ui);

	BOOL Create(HWND hTargetWnd);
	void Refresh();

protected:
	virtual void CustomizeMenu(HMENU hMenu);

	weasel::UIStyle &m_style;
	weasel::Status &m_status;
	WeaselTrayMode m_mode;
};

