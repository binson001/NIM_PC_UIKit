#ifndef __UIMENU_H__
#define __UIMENU_H__

#pragma once


namespace ui 
{
/////////////////////////////////////////////////////////////////////////////////////
//

enum MenuAlignment
{
	eMenuAlignment_Left = 1 << 1,
	eMenuAlignment_Top = 1 << 2,
	eMenuAlignment_Right = 1 << 3,
	eMenuAlignment_Bottom = 1 << 4,
};

/////////////////////////////////////////////////////////////////////////////////////
//

extern const TCHAR* const kMenuElementUIInterfaceName;// = _T("MenuElement);
class CMenuElementUI;
class CMenuWnd : public ui::WindowImplBase
{
public:
	virtual Control* CreateControl(const std::wstring& pstrClass) override;

	enum PopupPosType
	{
		RIGHT_BOTTOM,
		RIGHT_TOP
	};

	CMenuWnd(HWND hParent = NULL);
	void Init(STRINGorID xml, LPCTSTR pSkinType, POINT point, PopupPosType popupPosType = RIGHT_BOTTOM);
    std::wstring GetWindowClassName() const;

    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual std::wstring GetSkinFolder() override {
		return L"menu";
	}
	virtual std::wstring GetSkinFile() override {
		return m_xml.m_lpstr;
	}

	void Show();

public:
	HWND m_hParent;
	POINT m_BasedPoint;
	PopupPosType m_popupPosType;
	STRINGorID m_xml;
	std::wstring m_sType;
};

class ListContainerElement;
class CMenuElementUI : public ListContainerElement
{
	friend CMenuWnd;
public:
    CMenuElementUI();
	~CMenuElementUI();

	virtual bool ButtonUp(EventArgs& msg) override;
};

} // namespace ui

#endif // __UIMENU_H__
