#pragma once
#include <gtkmm/drawingarea.h>
class MyArea : public Gtk::DrawingArea
{
public:
	MyArea();
	virtual ~MyArea();
protected:
	//https://developer.gnome.org/gtkmm-tutorial/stable/sec-drawing-text.html.en
	//bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override; // gtkmm3�̏ꍇ
	//http://www.hakodate-ct.ac.jp/~tokai/tokai/gtkmm/img/p9.htm
	bool on_expose_event( GdkEventExpose* event );
private:
	void draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
	void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height);
};
