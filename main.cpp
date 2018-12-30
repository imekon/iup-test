#include <iup.h>

static int onOK(Ihandle *self)
{
	IupMessage("Hello World", "Cooo-eeee!");
	return IUP_CLOSE;
}

static int onClose(Ihandle *self)
{
	return IUP_CLOSE;
}

int WinMain()
{
	IupOpen(nullptr, nullptr);

	auto label = IupLabel("Hello world from IUP!");
	auto button = IupButton("OK", nullptr);
	auto box = IupHbox(label, button, nullptr);
	IupSetAttribute(box, "MARGIN", "10x10");
	IupSetAttribute(box, "GAP", "10");
	IupSetAttribute(box, "ALIGNMENT", "ACENTER");

	auto fileNew = IupItem("New", nullptr);
	auto fileOpen = IupItem("Open...", nullptr);
	auto fileSave = IupItem("Save As...", nullptr);
	auto fileExport = IupItem("Export...", nullptr);
	auto fileExit = IupItem("Exit", nullptr);

	IupSetCallback(fileExit, "ACTION", (Icallback)onClose);

	auto menuFile = IupMenu(fileNew, fileOpen, fileSave, IupSeparator(), fileExport, IupSeparator(), fileExit, nullptr);
	auto subMenuFile = IupSubmenu("File", menuFile);
	auto menu = IupMenu(subMenuFile, nullptr);

	auto dialog = IupDialog(box);
	IupSetAttributeHandle(dialog, "MENU", menu);
	IupSetAttribute(dialog, "TITLE", "Hello World!");
	IupSetAttribute(dialog, "SIZE", "600x400");
	IupSetCallback(button, "ACTION", (Icallback)onOK);
	IupShowXY(dialog, IUP_CENTER, IUP_CENTER);

	IupMainLoop();

	IupClose();

	return 0;
}