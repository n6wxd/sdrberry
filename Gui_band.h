#pragma once
#include "lvgl_.h"
#include <SoapySDR/ConverterRegistry.hpp>
#include <SoapySDR/Device.hpp>
#include <SoapySDR/Formats.hpp>
#include <SoapySDR/Modules.hpp>
#include <SoapySDR/Registry.hpp>
#include <SoapySDR/Types.hpp>
#include <SoapySDR/Version.hpp>
#include <vector>

#define MAX_BAND_BUTTONS 100

class Gui_band
{
  private:
	lv_obj_t *tab, *tileview, *main_tile, *edit_tile;
	//lv_obj_t *button[100];
	std::vector<lv_obj_t *> button;
	lv_obj_t *limitvfocheckbox, *bandfiltercheckbox;
	lv_style_t style_btn;

	int button_width;
	int button_height;
	int button_width_margin;
	int button_height_margin;
	int max_rows;
	lv_coord_t x_margin;
	lv_coord_t y_margin;
	int x_number_buttons;
	lv_coord_t tab_margin;
	
	lv_group_t *m_button_group{nullptr};
	std::vector<std::string> buttons;

	long f_min;
	long f_max;

	void band_event_handler_class(lv_event_t *e);
	void ham_event_handler_class(lv_event_t *e);
	void band_button_class(lv_event_t *e);
	

  public:
	static constexpr auto band_event_handler = EventHandler<Gui_band, &Gui_band::band_event_handler_class>::staticHandler;
	static constexpr auto ham_event_handler = EventHandler<Gui_band, &Gui_band::ham_event_handler_class>::staticHandler;
	static constexpr auto band_button = EventHandler<Gui_band, &Gui_band::band_button_class>::staticHandler;

	void init_button_gui(lv_obj_t *o_tab, lv_group_t *keyboard_group, lv_coord_t w, lv_coord_t h, SoapySDR::RangeList);

	void set_gui(int band);
	void set_group();
	void update_web();
	void reload_buttons();
	};

int getIndex(std::vector<int> v, int s);
extern Gui_band gui_band_instance;