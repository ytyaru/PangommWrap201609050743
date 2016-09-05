#include <gtkmm.h>
#include "myarea.h"
class MainWin : public Gtk::Window
{
	MyArea m_drawarea;
public:
	MainWin() {
		set_default_size(400,300);
		add( m_drawarea );
		show_all_children();
	}
};
int main(int argc, char* argv[])
{
	Gtk::Main kit( argc, argv );
	MainWin window;
	Gtk::Main::run( window );
	return 0;
}
