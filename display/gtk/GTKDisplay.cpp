/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include "GTKDisplay.hpp"
#include "PC/PCModule.hpp"
#include "time/TimeModule.hpp"

GTKDisplay::GTKDisplay()
{
        _modules.push_back(new TimeModule(20, 20, 300, 300));
}

GTKDisplay::~GTKDisplay()
{
}

bool GTKDisplay::setup()
{
        /* Création de la fenêtre */
        _window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        gtk_window_set_title(GTK_WINDOW(_window), "Rush 3");
        gtk_window_set_default_size(GTK_WINDOW(_window), 1280, 720);
        gtk_window_set_resizable(GTK_WINDOW(_window), TRUE);
        gtk_window_set_position(GTK_WINDOW(_window), GTK_WIN_POS_CENTER);

        _fixed = gtk_fixed_new();
        gtk_container_add(GTK_CONTAINER(_window), _fixed);
}

bool GTKDisplay::render()
{
        for (auto &e : _modules)
                e->render(*this);
	gtk_widget_show_all(_window);
	gtk_main();
}

bool GTKDisplay::clearRender()
{
}

bool GTKDisplay::refreshRender()
{
}

bool GTKDisplay::teardown()
{
}
