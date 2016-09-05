#include "MyArea.h"
#include <gtkmm.h>
#include <glibmm.h>
#include <string>
#include <pangomm.h>
#include <pangomm/fontdescription.h>

MyArea::MyArea(void)
{
}
MyArea::~MyArea(void)
{
}
bool MyArea::on_expose_event( GdkEventExpose* event )
{
	const int width = this->get_width();
	const int height = this->get_height();

	Cairo::RefPtr< Cairo::Context > cr = get_window()->create_cairo_context();
	
	cr->set_source_rgb(0.0, 0.0, 0.0);
	draw_rectangle(cr, width, height);

	cr->set_source_rgb(1.0, 1.0, 1.0);
	draw_text(cr, width, height);

	return true;
}
void MyArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
	cr->rectangle(0, 0, width, height);
	cr->fill();
}
void MyArea::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height)
{
	Pango::FontDescription font;
	
	font.set_family("MS gothic");
	font.set_weight(Pango::WEIGHT_NORMAL);
	font.set_size(24);
	
	Glib::RefPtr<Pango::Layout> layout = Pango::Layout::create(cr);
	layout->set_single_paragraph_mode(false);
	layout->set_width(rectangle_width * Pango::SCALE);
	layout->set_height(rectangle_height * Pango::SCALE);
	layout->set_wrap(Pango::WrapMode::WRAP_WORD); // WRAP_WORD, WRAP_CHAR, WRAP_WORD_CHAR

	Glib::ustring text = Glib::locale_to_utf8("長文で回り込み表示できるか。\n\nウインドウの長さに対して文字列が長いとき、自動で改行できるか。Pango::Layout::set_wrap()でできた。ただし事前にPango::Layout::set_width()する必要がある。このとき、幅の値にPango::SCALEの値を掛ける必要があることに注意する。さらにPango::Layout::set_single_paragraph_mode(false)する必要もある。デフォルトでfalseのようなので実行する必要はない。");
	layout->set_text(text);
	layout->set_font_description(font);
	int text_width;
	int text_height;
	layout->get_pixel_size(text_width, text_height);
	
	cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);

	layout->update_from_cairo_context(cr);

	layout->show_in_cairo_context(cr);
}