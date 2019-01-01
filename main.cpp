#include <iup.h>
#include <iupdraw.h>

#include "OpenFileDialog.h"
#include "AboutDialog.h"

static int onFileNew(Ihandle *self)
{
	return 0;
}

static int onFileOpen(Ihandle *self)
{
	OpenFileDialog dialog;
	if (dialog.showModal())
	{

	}

	return IUP_DEFAULT;
}

static int onFileSave(Ihandle *self)
{
	return IUP_DEFAULT;
}

static int onFileExport(Ihandle *self)
{
	return IUP_DEFAULT;
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

static int onSongAction(Ihandle *canvas)
{
	int width, height;

	IupDrawBegin(canvas);

	IupDrawGetSize(canvas, &width, &height);

	IupSetAttribute(canvas, "DRAWCOLOR", "192 192 192");
	IupSetAttribute(canvas, "DRAWSTYLE", "FILL");
	IupDrawRectangle(canvas, 0, 0, width - 1, height - 1);

	IupSetAttribute(canvas, "DRAWCOLOR", "0 0 0");
	IupSetAttribute(canvas, "DRAWSTYLE", "STROKE");
	IupDrawRectangle(canvas, 10, 10, 40, 30);

	IupDrawEnd(canvas);

	return IUP_DEFAULT;
}

static int onPatternAction(Ihandle *canvas)
{
	int width, height;

	IupDrawBegin(canvas);

	IupDrawGetSize(canvas, &width, &height);

	IupDrawEnd(canvas);

	return IUP_DEFAULT;
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

	auto canvasSong = IupCanvas(nullptr);
	auto canvasPattern = IupCanvas(nullptr);
	IupSetAttribute(canvasSong, "EXPAND", "YES");
	IupSetAttribute(canvasPattern, "EXPAND", "YES");
	IupSetCallback(canvasSong, "ACTION", (Icallback)onSongAction);
	IupSetCallback(canvasPattern, "ACTION", (Icallback)onPatternAction);
	auto songBox = IupVbox(canvasSong, nullptr);
	auto patternBox = IupVbox(canvasPattern, nullptr);

	IupSetAttribute(songBox, "TABTITLE", "Song");
	IupSetAttribute(patternBox, "TABTITLE", "Pattern");

	auto tab = IupTabs(songBox, patternBox, nullptr);

	auto box = IupVbox(tab, nullptr);
	IupSetAttribute(box, "MARGIN", "10x10");
	IupSetInt(box, "GAP", 10);

	auto dialog = IupDialog(box);
	IupSetAttributeHandle(dialog, "MENU", menu);
	IupSetAttribute(dialog, "TITLE", "Hello World!");
	IupSetAttribute(dialog, "SIZE", "600x400");
	IupShowXY(dialog, IUP_CENTER, IUP_CENTER);

	IupMainLoop();

	IupClose();

	return 0;
}