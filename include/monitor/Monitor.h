//
// Created by Амир Кашапов on 24.02.2024.
//

#ifndef UNTITLED_MONITOR_H
#define UNTITLED_MONITOR_H

// Non-selfmade library for UI realisation
#include <ncurses.h>
#include <vector>
#include <map>
#include <memory>
#include <actions/Action.h>
#include <navigation/Map.h>
#include "events/EnemyEncounter.h"
class Player;
//       x --->
//  y
//  |
//  |
//  \/



//At this moment ncurses mode starts with initialistion of Monitor
class Monitor{
public:
    void setBuffer(std::string new_string);
    Monitor();
    ~Monitor() = default;


    void draw(Player* player);//Ask draw functions realizations from Map, Entity and Event if needed


    void keyEvent(int key, Player* player);
    void keyEvent(Player* player);

private:


    // Don't want to give access to GameWindow and its childs in other files, it's only for Monitor usage
    class GameWindow {
        public:
        friend Monitor;
            GameWindow();
            GameWindow(const GameWindow& other);
            ~GameWindow() = default;
            GameWindow(const size_t& pos_y, const size_t& pos_x, const size_t& y_size, const size_t& x_size);
            void clean();

            //Just placing sprite or text without clearing all previous text
            void draw_sprite(const size_t& pos_y, const size_t& pos_x,
                            const std::vector<std::vector<char>>& sprite, bool skip_spaces = false, int attribute = A_NORMAL);
            void draw_text(const size_t& pos_y, const size_t& pos_x,
                            const std::string& text, bool skip_spaces = false, int attribute = A_NORMAL) ;

            void clear_atr(size_t row = 0, size_t col = 0, int num = -1);
            size_t get_x() const;
            size_t get_y() const;
            void set_atr(size_t row, size_t col, size_t num = 1, attr_t atr = A_NORMAL, short color = 0);

        protected:
            WINDOW* m_current_window;
            size_t m_x_size;
            size_t m_y_size;
    };

    class InterfaceColumnWindow : public GameWindow {
        public:
            InterfaceColumnWindow();
            InterfaceColumnWindow(const size_t& y_size, const size_t& x_size, const size_t& pos_y, const size_t& pos_x);
            InterfaceColumnWindow(const InterfaceColumnWindow& other);
            ~InterfaceColumnWindow() = default;
            friend Monitor;
            int find_bind_key(std::shared_ptr<actions::Action> action);
            std::shared_ptr<actions::Action> find_action(int key);
            void draw_interface(std::set<std::shared_ptr<actions::Action>> available_actions, bool adaptive = true);
            void get_binds(Player* player);
        private:
            class Bind{
            public:
                Bind();

                Bind(const std::shared_ptr<actions::Action>& action);
                std::shared_ptr<actions::Action> getAction();
                std::function<void(Player*)> getFunction();
            private:
                std::function<void(Player*)> m_function;
                std::shared_ptr<actions::Action> m_action;

            };
            std::vector<GameWindow> m_columns;
            int m_first_unbind = 'a';
            std::map<int, Bind> m_key_binds;
    };

    static void abs_coordinates_to_relative(int& row, int& col, const GameWindow& cur_window, Position center);
    static void init_colors();
    static std::shared_ptr<events::EnemyEncounter> have_battle(Player* player);
    
    static std::string get_entity_characteristics(std::shared_ptr<entity::Entity> person);
    bool m_draw_Characteristis = false;
    bool m_have_battle = false;
    bool m_if_skill_selected = false;
    int m_selected_skill = -1;
    std::string m_buffer = "DEBUG"; 
    std::vector<GameWindow> m_inventory_display;
    InterfaceColumnWindow m_user_actions_display;
    GameWindow m_map_display;
    GameWindow m_characteristics_display;
    std::vector<GameWindow> m_entity_window;
    GameWindow m_background_display;
};
#endif //UNTITLED_MONITOR_H
