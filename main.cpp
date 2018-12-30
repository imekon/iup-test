#include <iup.h>

#include "AboutDialog.h"

static int onFileNew(Ihandle *self)
{
	return 0;
}

static int onFileOpen(Ihandle *self)
{
	return 0;
}

static int onFileSave(Ihandle *self)
{
	return 0;
}

static int onFileExport(Ihandle *self)
{
	return 0;
}

static int onEditCut(Ihandle *self)
{
	return 0;
}

static int onEditCopy(Ihandle *self)
{
	return 0;
}

static int onEditPaste(Ihandle *self)
{
	return 0;
}

static int onHelpAbout(Ihandle *self)
{
	AboutDialog dialog;
	dialog.showModal();

	return 0;
}

static int onFileExit(Ihandle *self)
{
	return IUP_CLOSE;
}

int WinMain()
{
	IupOpen(nullptr, nullptr);

	auto fileNew = IupItem("New", nullptr);
	auto fileOpen = IupItem("Open...", nullptr);
	auto fileSave = IupItem("Save As...", nullptr);
	auto fileExport = IupItem("Export...", nullptr);
	auto fileExit = IupItem("Exit", nullptr);

	auto editCut = IupItem("Cut", nullptr);
	auto editCopy = IupItem("Copy", nullptr);
	auto editPaste = IupItem("Paste", nullptr);

	auto helpAbout = IupItem("About...", nullptr);

	IupSetCallback(fileNew, "ACTION", (Icallback)onFileNew);
	IupSetCallback(fileOpen, "ACTION", (Icallback)onFileOpen);
	IupSetCallback(fileSave, "ACTION", (Icallback)onFileSave);
	IupSetCallback(fileExport, "ACTION", (Icallback)onFileExport);
	IupSetCallback(fileExit, "ACTION", (Icallback)onFileExit);

	IupSetCallback(editCut, "ACTION", (Icallback)onEditCut);
	IupSetCallback(editCopy, "ACTION", (Icallback)onEditCopy);
	IupSetCallback(editPaste, "ACTION", (Icallback)onEditPaste);

	IupSetCallback(helpAbout, "ACTION", (Icallback)onHelpAbout);

	auto menuFile = IupMenu(fileNew, fileOpen, fileSave, IupSeparator(), fileExport, IupSeparator(), fileExit, nullptr);
	auto menuEdit = IupMenu(editCut, editCopy, editPaste, nullptr);
	auto menuHelp = IupMenu(helpAbout, nullptr);
	auto subMenuFile = IupSubmenu("File", menuFile);
	auto subMenuEdit = IupSubmenu("Edit", menuEdit);
	auto subMenuHelp = IupSubmenu("Help", menuHelp);
	auto menu = IupMenu(subMenuFile, subMenuEdit, subMenuHelp, nullptr);

	auto box = IupVbox(nullptr);

	auto dialog = IupDialog(box);
	IupSetAttributeHandle(dialog, "MENU", menu);
	IupSetAttribute(dialog, "TITLE", "Hello World!");
	IupSetAttribute(dialog, "SIZE", "600x400");
	IupShowXY(dialog, IUP_CENTER, IUP_CENTER);

	IupMainLoop();

	IupClose();

	return 0;
}