#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

void deleter(std::string& all_txt, int count) {
  std::string check;
  for (int i = 0; i < count; ++i) {
    check += all_txt[i];
  }
  for (int i = count + 1; i < all_txt.size(); ++i) {
    check += all_txt[i];
  }
  all_txt = check;
}

void add(std::string& all_txt, int count, std::string added) {
  std::string check;
  for (int i = 0; i < count; ++i) {
    check += all_txt[i];
  }
  check += added;
  for (int i = count; i < all_txt.size(); ++i) {
    check += all_txt[i];
  }
  all_txt = check;
}

int EnterK() {
  int k = 0;
  sf::RenderWindow enter_n(sf::VideoMode(500, 100), "Enter K");
  std::string entered;
  sf::Text enter_your_text;
  sf::Text text;
  sf::Font font;
  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter K (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_n.draw(enter_your_text);
  enter_n.display();

  text.setFont(font);
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_n.isOpen()) {
    sf::Event event;
    while (enter_n.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        return k;
      }
      if (event.type == sf::Event::TextEntered && event.text.unicode <= 57 && event.text.unicode >= 48) {
        entered += static_cast<char>(event.text.unicode);
        enter_n.clear();
        text.setString(entered);
        enter_n.draw(text);
        enter_n.draw(enter_your_text);
        enter_n.display();
        k *= 10;
        k += event.text.unicode - 48;
      }
    }
  }
}

int EnterN() {
  int n = 0;
  sf::RenderWindow enter_n(sf::VideoMode(500, 100), "Enter N");
  sf::Text enter_your_text;
  sf::Text text;
  std::string entered;
  sf::Font font;
  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter N (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_n.draw(enter_your_text);
  enter_n.display();

  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_n.isOpen()) {
    sf::Event event;
    while (enter_n.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        return n;
      }
      if (event.type == sf::Event::TextEntered && event.text.unicode <= 57 && event.text.unicode >= 48) {
        entered += static_cast<char>(event.text.unicode);
        enter_n.clear();
        text.setString(entered);
        enter_n.draw(text);
        enter_n.draw(enter_your_text);
        enter_n.display();
        n *= 10;
        n += event.text.unicode - 48;
      }
    }
  }
}

std::string EnterFinding() {
  sf::RenderWindow enter_n(sf::VideoMode(500, 100), "Enter N");
  sf::Text enter_your_text;
  sf::Text output_txt;
  std::string entered;
  sf::Font font;
  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter find (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_n.draw(enter_your_text);
  enter_n.display();

  output_txt.setFont(font); //  вывод введенного текста
  output_txt.setPosition(0, 60);
  output_txt.setString("");
  output_txt.setCharacterSize(24);
  output_txt.setStyle(sf::Text::Bold);

  while (enter_n.isOpen()) {
    sf::Event event;
    while (enter_n.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        return entered;
      }
      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        entered += static_cast<char>(event.text.unicode);
        enter_n.clear();
        output_txt.setString(entered);
        enter_n.draw(output_txt);
        enter_n.draw(enter_your_text);
        enter_n.display();
      }
    }
  }
}

void displayButtons(sf::RenderWindow& window, std::vector<sf::RectangleShape*> button_area) {
  for (int i = 0; i < 10; ++i) {
    window.draw(*button_area[i]);
  }
  sf::Font font;
  font.loadFromFile("CyrilicOld.ttf");

  sf::Text button_text;
  button_text.setFont(font); // text_x
  button_text.setCharacterSize(24);
  button_text.setStyle(sf::Text::Bold);
  button_text.setFillColor(sf::Color::Black);
  button_text.setOutlineColor(sf::Color::Black);
  std::vector <std::string> button_num = { "1","2", "3", "4", "5", "6", "7", "8", "9", "10" };
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      button_text.setString(button_num[i*2 + j]);
      button_text.setPosition(900 + 200 * j, 80 + 160 * i);
      window.draw(button_text);
    }
  }
  sf::Text enter_your_text;
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your text here");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  window.draw(enter_your_text);
}

void TextEntering(sf::RenderWindow& window,std::string& input, std::vector <std::string>& output_txt, int& count_output_txt, bool is_button_window) {
  sf::Font font;
  sf::Text text;
  sf::Text enter_your_text;
  font.loadFromFile("CyrilicOld.ttf");
  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  if (is_button_window) {
    enter_your_text.setString("Enter your text (press Enter after you finish)");
  }
  else {
    enter_your_text.setString("Enter your text here");
  }

  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  std::string checker;
  sf::Text width_checker;

  width_checker.setFont(font); // просьба ввести текст
  width_checker.setCharacterSize(24);
  width_checker.setStyle(sf::Text::Bold);
  checker += output_txt[count_output_txt];
  checker += input;
  width_checker.setString(checker);
  if (width_checker.getLocalBounds().width > 800) {
    ++count_output_txt;
    output_txt.resize(count_output_txt + 1);
  }
  output_txt[count_output_txt] += input;
  for (int i = 0; i < count_output_txt + 1; ++i) {
    text.setString(output_txt[i]);
    text.setPosition(0, 60 + 30 * i);
    window.draw(text);
  }
  window.draw(enter_your_text);
  window.display();
}

void button_1(std::vector <std::string>& all_txt, int sizeof_all_txt,  int n) {
  sf::RenderWindow enter_one(sf::VideoMode(800, 800), "Enter you're text please");
  std::vector <std::string> output_txt(1);
  std::vector <std::string> copy(1);
  sf::Text enter_your_text;
  sf::Font font;

  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your text (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_one.draw(enter_your_text);
  enter_one.display();

  int count_output_txt = 0;

  while (enter_one.isOpen()) {
    sf::Event event;
    while (enter_one.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        int count_pos = 0;
        if (n == 0) {
          n = 1;
        }
        else if (n > sizeof_all_txt + 1) {
          n = sizeof_all_txt + 2;
        }
        for (int i = 0; i < n - 1; ++i) {
          copy[count_pos] = all_txt[i];
          ++count_pos;
          copy.resize(count_pos + 1);
        }
        for (int i = 0; i < output_txt.size(); ++i) {
          copy[count_pos] = output_txt[i];
          ++count_pos;
          copy.resize(count_pos + 1);
        }
        for (int i = n - 1; i < all_txt.size(); ++i) {
          copy[count_pos] = all_txt[i];
          ++count_pos;
          copy.resize(count_pos + 1);
        }
        all_txt.resize(copy.size());
        for (int i = 0; i < all_txt.size(); ++i) {
          all_txt[i] = copy[i];
        }
        enter_one.close();
      }

      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        enter_one.clear();
        std::string input;
        input = static_cast<char>(event.text.unicode);
        TextEntering(enter_one, input, output_txt, count_output_txt, 1);
      }
    }
  }
}

void button_3(std::vector <std::string>& all_txt, int sizeof_all_txt, int n) {
  sf::RenderWindow enter_one(sf::VideoMode(800, 800), "Enter you're text please");
  sf::Text enter_your_text;
  sf::Text text;
  sf::Font font;
  std::vector <std::string> output_txt(1);
  int count = 0;

  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your text (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_one.draw(enter_your_text);
  enter_one.display();

  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_one.isOpen()) {

    sf::Event event;
    while (enter_one.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        enter_one.close();
      }
      if (n == 0) {
        n = 1;
      }
      for (int i = n - 1; i < sizeof_all_txt; ++i) {
        all_txt[i] = all_txt[i + 1];
      }
      all_txt.resize(all_txt.size() - 1);
      enter_one.close();
    }
  }
}

void button_4(std::vector <std::string>& all_txt, int sizeof_all_txt, int n, int k) {
  sf::RenderWindow enter_one(sf::VideoMode(800, 800), "Enter you're text please");
  sf::Text enter_your_text;
  sf::Text text;
  sf::Font font;
  std::vector <std::string> output_txt(1);

  int count_output_txt = 0;

  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your text (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_one.draw(enter_your_text);
  enter_one.display();

  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_one.isOpen()) {

    sf::Event event;

    while (enter_one.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        enter_one.close();
      }
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        std::string check;
        if (n == 0) {
          n = 1;
        }
        else if (n > sizeof_all_txt + 2) {
          n = sizeof_all_txt + 2;
          all_txt.resize(n);
          all_txt[n - 1] = "";
        }
        if (k > all_txt[n - 1].size() + 1) {
          k = all_txt[n - 1].size() + 1;
        }

        for (int i = 0; i < k - 1; ++i) {
          check += all_txt[n - 1][i];
        }

        for (int i = 0; i < count_output_txt + 1; ++i) {
          check += output_txt[i];
        }

        for (int i = k - 1; i < all_txt[n - 1].size(); ++i) {
          check += all_txt[n - 1][i];
        }

        int count_for_text = n - 1;
        int count_for_checking = 0;
        bool exit = 1;
        std::vector <std::string> buffer(all_txt.size() - n);
        for (int i = n; i < all_txt.size(); ++i) {
          buffer[i - n] = all_txt[i];
        }

        while (exit) {
          sf::Text cheker;
          std::string cheking = "";
          cheker.setFont(font); //  вывод введенного текста
          cheker.setPosition(0, 60);
          cheker.setString("");
          cheker.setCharacterSize(24);
          cheker.setStyle(sf::Text::Bold);
          for (count_for_checking;; ++count_for_checking) {
            if (count_for_checking == check.size() - 1) {
              cheking += check[count_for_checking];
              all_txt[count_for_text] = cheking;
              exit = 0;
              break;
            }
            cheker.setString(cheking + check[count_for_checking]);
            if (cheker.getLocalBounds().width < 800) {
              cheking += check[count_for_checking];
            }
            else {
              all_txt[count_for_text] = cheking;
              ++count_for_text;
              if (count_for_text > all_txt.size()) {
                all_txt.resize(count_for_text + 1);
              }
              break;
            }
          }
        }
        for (int i = count_for_text + 1; i < count_for_text + 1 + buffer.size(); ++i) {
          if (i >= all_txt.size() - 1) {
            all_txt.resize(i + 1);
          }
          all_txt[i] = buffer[i - count_for_text - 1];
        }
        enter_one.close();
      }

      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        enter_one.clear();

        std::string checker;
        std::string input;

        sf::Text check;
        font.loadFromFile("CyrilicOld.ttf");
        check.setFont(font); // просьба ввести текст
        check.setCharacterSize(24);
        check.setStyle(sf::Text::Bold);

        input = static_cast<char>(event.text.unicode);
        checker += output_txt[count_output_txt];
        checker += input;
        std::cout << checker << std::endl;
        check.setString(checker);

        if (check.getLocalBounds().width > 800) {
          ++count_output_txt;
          output_txt.resize(count_output_txt + 1);
        }
        std::cout << check.getLocalBounds().width << std::endl;
        output_txt[count_output_txt] += input;

        for (int i = 0; i < count_output_txt + 1; ++i) {
          text.setString(output_txt[i]);
          text.setPosition(0, 60 + 30 * i);
          enter_one.draw(text);
        }
        enter_one.draw(enter_your_text);
        enter_one.display();
      }
    }
  }
}

void button_5(std::vector <std::string>& all_txt, int sizeof_all_txt, int n, int k) {
  sf::RenderWindow enter_one(sf::VideoMode(800, 800), "Enter you're text please");
  sf::Text enter_your_text;
  sf::Text text;
  sf::Font font;
  std::vector <std::string> output_txt(1);

  int count_output_txt = 0;

  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your text (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_one.draw(enter_your_text);
  enter_one.display();

  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_one.isOpen()) {

    sf::Event event;

    while (enter_one.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        enter_one.close();
      }
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        std::string check;
        if (n == 0) {
          n = 1;
        }
        else if (n > sizeof_all_txt + 2) {
          n = sizeof_all_txt + 2;
          all_txt.resize(n);
          all_txt[n - 1] = "";
        }
        if (k > all_txt[n - 1].size() + 1) {
          k = all_txt[n - 1].size() + 1;
        }

        for (int i = 0; i < k - 1; ++i) {
          check += all_txt[n - 1][i];
        }

        for (int i = 0; i < count_output_txt + 1; ++i) {
          check += output_txt[i];
        }

        for (int i = k; i < all_txt[n - 1].size(); ++i) {
          check += all_txt[n - 1][i];
        }

        int count_for_text = n - 1;
        int count_for_checking = 0;
        bool exit = 1;
        std::vector <std::string> buffer(all_txt.size() - n);
        for (int i = n; i < all_txt.size(); ++i) {
          buffer[i - n] = all_txt[i];
        }

        while (exit) {
          sf::Text cheker;
          std::string cheking = "";
          cheker.setFont(font); //  вывод введенного текста
          cheker.setPosition(0, 60);
          cheker.setString("");
          cheker.setCharacterSize(24);
          cheker.setStyle(sf::Text::Bold);
          for (count_for_checking;; ++count_for_checking) {
            if (count_for_checking == check.size() - 1) {
              cheking += check[count_for_checking];
              all_txt[count_for_text] = cheking;
              exit = 0;
              break;
            }
            cheker.setString(cheking + check[count_for_checking]);
            if (cheker.getLocalBounds().width < 800) {
              cheking += check[count_for_checking];
            }
            else {
              all_txt[count_for_text] = cheking;
              ++count_for_text;
              if (count_for_text >= all_txt.size()) {
                all_txt.resize(count_for_text + 1);
              }
              break;
            }
          }
        }
        for (int i = count_for_text + 1; i < count_for_text + 1 + buffer.size(); ++i) {
          if (i >= all_txt.size() - 1) {
            all_txt.resize(i + 1);
          }
          all_txt[i] = buffer[i - count_for_text - 1];
        }
        enter_one.close();
      }

      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        enter_one.clear();
        std::string input;
        input = static_cast<char>(event.text.unicode);
        TextEntering(enter_one, input, output_txt, count_output_txt, 1);
      }
    }
  }
}

void button_6(std::vector <std::string>& all_txt, int sizeof_all_txt, std::string find, int n, int k) {
  sf::RenderWindow enter_one(sf::VideoMode(800, 800), "Enter you're text please");
  sf::Text enter_your_text;
  sf::Text text;
  sf::Font font;
  std::vector <std::string> output_txt(1);
  std::string added;
  int count_output_txt = 0;
  font.loadFromFile("CyrilicOld.ttf");
  enter_your_text.setFont(font); // просьба ввести текст
  enter_your_text.setPosition(0, 0);
  enter_your_text.setString("Enter your changing (press Enter after you finish)");
  enter_your_text.setCharacterSize(24);
  enter_your_text.setStyle(sf::Text::Bold);
  enter_one.draw(enter_your_text);
  enter_one.display();

  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  while (enter_one.isOpen()) {

    sf::Event event;

    while (enter_one.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        enter_one.close();
      }
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        if (n > all_txt.size() || k > all_txt.size()) {
          return;
        }
        else if (n > k) {
          int change = n;
          n = k;
          k = change;
        }
        added = output_txt[0];
        int count_for_text = 0;
        std::string check;
        for (int count = n - 1; count < k; ++count) {
          check = all_txt[count];
          bool exit = 1;
          for (int i = 0; i < check.size() - find.size() + 1; ++i) {
            if (check[i] == find[0]) {
              for (int j = 0; j < find.size(); ++j) {
                if (check[i + j] != find[j]) {
                  i += j - 1;
                  break;
                }
                else if (j == find.size() - 1) {
                  for (int f = 0; f < find.size(); ++f) {
                    deleter(check, i);
                  }
                  add(check, i, added);
                  i += added.size() - 1;
                  break;
                }
              }
            }
          }
          while (exit) {
            sf::Text cheker;
            std::string check_text = "";
        
            cheker.setFont(font); //  вывод введенного текста
            cheker.setPosition(0, 60);
            cheker.setString("");
            cheker.setCharacterSize(24);
            cheker.setStyle(sf::Text::Bold);
        
            for (int count_for_checking = 0;; ++count_for_checking) {
              if (count_for_checking == check.size() - 1) {
                check_text += check[count_for_checking];
                output_txt[count_for_text] = check_text;
                ++count_for_text;
                if (count_for_text >= output_txt.size()) {
                  output_txt.resize(count_for_text + 1);
                }
                exit = 0;
                break;
              }
              cheker.setString(check_text + check[count_for_checking]);
              if (cheker.getLocalBounds().width < 800) {
                check_text += check[count_for_checking];
              }
              else {
                output_txt[count_for_text] = check_text;
                check_text = "";
                ++count_for_text;
                --count_for_checking;
                if (count_for_text >= output_txt.size()) {
                  output_txt.resize(count_for_text + 1);
                }
              }
            }
          }
        }
        std::vector <std::string> copy(all_txt.size());
        for (int i = 0; i < all_txt.size(); ++i) {
          copy[i] = all_txt[i];
        }
        if (count_for_text - 1 > k - n) {
          all_txt.resize(all_txt.size() + count_for_text - k + n - 1);
        }
        for (int i = n - 1; i < n + count_for_text - 1; ++i) {
          all_txt[i] = output_txt[i - n + 1];
        }
        for (int i = n + count_for_text - 1; i < all_txt.size(); ++i) {
          all_txt[i] = copy[i - n - count_for_text + 1];
        }
        enter_one.close();
      }
      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        enter_one.clear();
        std::string input;
        input = static_cast<char>(event.text.unicode);
        TextEntering(enter_one, input, output_txt, count_output_txt, 1);
      }
    }
  }
}

void button_7(std::vector <std::string>& all_txt, int sizeof_all_txt, int n, int k) {
  sf::Text text;
  sf::Font font;

  font.loadFromFile("CyrilicOld.ttf");
  text.setFont(font); //  вывод введенного текста
  text.setPosition(0, 60);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);
  std::string check;
  bool is_not_vedushiy = 0;
  int count_empty = 0;
  for (int i = n - 1; i < k; ++i) {
    check = all_txt[i];
    for (int j = 0; j < check.size() - 1; ++j) {
      if (check[j] == '0' && is_not_vedushiy) {
        continue;
      }
      else if (check[j] == '0' && !is_not_vedushiy) {
        if (static_cast<int>(check[j + 1]) >= 48 && static_cast<int>(check[j + 1]) <= 57) {
          deleter(check, j);
          --j;
        }
        else {
          continue;
        }
      }
      else if (static_cast<int>(check[j]) >= 49 && static_cast<int>(check[j]) <= 57) {
        is_not_vedushiy = 1; 
      }
      else {
        is_not_vedushiy = 0;
      }
    }
    all_txt[i - count_empty] = check;
    if (check == "") {
      ++count_empty;
    }
  }
}

void button_8(std::vector <std::string>& all_txt, int sizeof_all_txt) {

  int count_empty = 0;
  std::string check;
  for (int i = 0; i < all_txt.size(); ++i) {
    check = all_txt[i];
    bool is_after_num = 0;
    int max_num = -1;
    int start_pos = -1;
    bool is_true_numeration = 0;

    for (int j = 0; j < check.size(); ++j) {
      if (static_cast<int>(check[j]) >= 48 && static_cast<int>(check[j]) <= 57 && !is_after_num) {
        max_num = static_cast<int>(check[j]) - 48;
        start_pos = j;
        is_after_num = 1;
      }
      else if (static_cast<int>(check[j]) >= 48 && static_cast<int>(check[j]) <= 57 && is_after_num) {
        if (static_cast<int>(check[j]) - 48 <= max_num) {
          max_num = 10;
          is_true_numeration = 0;
        } else {
          is_true_numeration = 1;
          max_num = static_cast<int>(check[j]) - 48;
        }
      }
      else if (is_after_num && is_true_numeration) {
        max_num = -1;
        is_after_num = 0;
        is_true_numeration = 0;
        start_pos = -1;
      }
      else if (start_pos != -1) {
        for (int f = start_pos; f < j; ++f) {
          deleter(check, start_pos);
        }
        max_num = -1;
        is_after_num = 0;
        is_true_numeration = 0;
        j = start_pos - 1;
        start_pos = -1;
      }
      if (j == check.size() - 1 && start_pos != -1 && (!is_true_numeration || !is_after_num)) {
        if (static_cast<int>(check[j]) >= 48 && static_cast<int>(check[j]) <= 57) {
          for (int f = start_pos; f <= j; ++f) {
            deleter(check, start_pos);
          }
        }
        else {
          for (int f = start_pos; f < j; ++f) {
            deleter(check, start_pos);
          }
        }
      }
    }
    all_txt[i - count_empty] = check;
    if (check == "") {
      ++count_empty;
    }
  }
  for (int i = sizeof_all_txt - count_empty + 1; i < sizeof_all_txt + 1; ++i) {
    all_txt[i] = "";
  }
}

void button_9(std::vector <std::string>& all_txt, int sizeof_all_txt) {
  std::string check;
  for (int i = 0; i < all_txt.size(); ++i) {
    check = all_txt[i];
    int count_stars = 0;
    int count_empty = 0;
    for (int j = 0; j < check.size(); ++j) {
      if (check[j] == '*') {
        ++count_stars;
      }
      else if (check[j] != '*' && count_stars > 0) {
        for (int f = j - count_stars; f < j + 1; ++f) {
          deleter(check, j - count_stars);
        }
        j = j - count_stars;
        for (int f = j; f < j + (count_stars + 1) / 2; ++f) {
          add(check, f, "+");
        }
        j = j + count_stars / 2;
        count_stars = 0;
      }
    }
    if (count_stars > 0) {
      int delet_pos = check.size() - count_stars;
      for (int f = delet_pos; f < delet_pos + count_stars; ++f) {
        deleter(check, delet_pos);
      }
       int add_pos = delet_pos;
      for (int f = add_pos; f < add_pos + (count_stars + 1) / 2; ++f) {
        add(check, f, "+");
      }
      count_stars = 0;
    }
    all_txt[i - count_empty] = check;
    if (check == "") {
      ++count_empty;
    }
  }
}

void button_10(std::vector <std::string>& all_txt, int sizeof_all_txt, int n) {
  int count_empty = 0;
  std::string check;
  bool is_in_brackets = 0;
  int start_of_brackets = -1;
  check = all_txt[n - 1];
  for (int j = 0; j < check.size(); ++j) {
    if (check[j] == '{' && !is_in_brackets) {
      is_in_brackets = 1;
      start_of_brackets = j;
    }
    else if (check[j] == '}' && is_in_brackets) {
      for (int f = start_of_brackets; f <= j; ++f) {
        deleter(check, start_of_brackets);
      }
      j = start_of_brackets;
      is_in_brackets = 0;
    }
  }
  all_txt[n - 1] = check;
  if (check == "") {
    ++count_empty;
  }
  for (int i = n; i <= sizeof_all_txt; ++i) {
    all_txt[i - count_empty] = all_txt[i];
  }
  for (int i = sizeof_all_txt - count_empty + 1; i < sizeof_all_txt + 1; ++i) {
    all_txt[i] = "";
  }
}

void frontend() {
  sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");


  std::vector <std::string> all_txt(1);

  sf::Font font;
  font.loadFromFile("CyrilicOld.ttf");

  sf::Text text;
  text.setFont(font); // text_x
  text.setPosition(0, 0);
  text.setString("");
  text.setCharacterSize(24);
  text.setStyle(sf::Text::Bold);

  int a = 160;
  int b = 150;

  std::vector<sf::RectangleShape*> button_area(10);
  sf::RectangleShape buttons_area_0(sf::Vector2f(a, b));
  buttons_area_0.setPosition(800, 0);
  buttons_area_0.setOutlineColor(sf::Color::Black);
  button_area[0] = &buttons_area_0;

  sf::RectangleShape buttons_area_1(sf::Vector2f(a, b));
  buttons_area_1.setPosition(1000, 0);
  buttons_area_1.setOutlineColor(sf::Color::Black);
  button_area[1] = &buttons_area_1;

  sf::RectangleShape buttons_area_2(sf::Vector2f(a, b));
  buttons_area_2.setPosition(800, 160);
  buttons_area_2.setOutlineColor(sf::Color::Black);
  button_area[2] = &buttons_area_2;

  sf::RectangleShape buttons_area_3(sf::Vector2f(a, b));
  buttons_area_3.setPosition(1000, 160);
  buttons_area_3.setOutlineColor(sf::Color::Black);
  button_area[3] = &buttons_area_3;

  sf::RectangleShape buttons_area_4(sf::Vector2f(a, b));
  buttons_area_4.setPosition(800, 320);
  buttons_area_4.setOutlineColor(sf::Color::Black);
  button_area[4] = &buttons_area_4;

  sf::RectangleShape buttons_area_5(sf::Vector2f(a, b));
  buttons_area_5.setPosition(1000, 320);
  buttons_area_5.setOutlineColor(sf::Color::Black);
  button_area[5] = &buttons_area_5;

  sf::RectangleShape buttons_area_6(sf::Vector2f(a, b));
  buttons_area_6.setPosition(800, 480);
  buttons_area_6.setOutlineColor(sf::Color::Black);
  button_area[6] = &buttons_area_6;

  sf::RectangleShape buttons_area_7(sf::Vector2f(a, b));
  buttons_area_7.setPosition(1000, 480);
  buttons_area_7.setOutlineColor(sf::Color::Black);
  button_area[7] = &buttons_area_7;

  sf::RectangleShape buttons_area_8(sf::Vector2f(a, b));
  buttons_area_8.setPosition(800, 640);
  buttons_area_8.setOutlineColor(sf::Color::Black);
  button_area[8] = &buttons_area_8;

  sf::RectangleShape buttons_area_9(sf::Vector2f(a, b));
  buttons_area_9.setPosition(1000, 640);
  buttons_area_9.setOutlineColor(sf::Color::Black);
  button_area[9] = &buttons_area_9;

  displayButtons(window, button_area);
  window.display();
  int count_output_txt = 0;

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
    
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        double local_x = (sf::Mouse::getPosition(window).x);
        double local_y = (sf::Mouse::getPosition(window).y);
        if (local_x >= 800 && local_x <= 1200 && local_y >= 0 && local_y <= 155) {
          int n = EnterN();
          button_1(all_txt, all_txt.size() - 1, n);
          count_output_txt = all_txt.size() - 1;
          window.clear();

          for (int i = 0; i < all_txt.size(); ++i) {
            if (all_txt[i] != "") {
              text.setString(all_txt[i]);
              text.setPosition(0, 60 + 30 * i);
              window.draw(text);
            }
            else {
              all_txt.erase(all_txt.begin() + i);
              count_output_txt = all_txt.size() - 1;
              --i;
            }
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 800 && local_x <= 1000 && local_y >= 160 && local_y <= 320) {
          int n = EnterN();
          if (n <= all_txt.size()) {
            button_3(all_txt, count_output_txt, n);
            count_output_txt = all_txt.size() - 1;
          }
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 1000 && local_x <= 1200 && local_y >= 160 && local_y <= 320) {
          int n = EnterN();
          int k = EnterK();
          button_4(all_txt, count_output_txt, n, k);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 800 && local_x <= 1000 && local_y >= 320 && local_y <= 480) {
          int n = EnterN();
          int k = EnterK();
          button_5(all_txt, count_output_txt, n, k);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 1000 && local_x <= 1200 && local_y >= 320 && local_y <= 480) {
          std::string find = EnterFinding();
          int n = EnterN();
          int k = EnterK();
          button_6(all_txt, count_output_txt, find, n, k);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 800 && local_x <= 1000 && local_y >= 480 && local_y <= 640) {
          int n = EnterN();
          int k = EnterK();
          button_7(all_txt, count_output_txt, n, k);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 1000 && local_x <= 1200 && local_y >= 480 && local_y <= 640) {
          button_8(all_txt, count_output_txt);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 800 && local_x <= 1000 && local_y >= 640 && local_y <= 800) {
          button_9(all_txt, count_output_txt);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        }
        else if (local_x >= 1000 && local_x <= 1200 && local_y >= 640 && local_y <= 800) {
          int n = EnterN();
          button_10(all_txt, count_output_txt, n);
          count_output_txt = all_txt.size() - 1;
          window.clear();
          for (int i = 0; i < all_txt.size(); ++i) {
            text.setString(all_txt[i]);
            text.setPosition(0, 60 + 30 * i);
            window.draw(text);
          }
          displayButtons(window, button_area);
          window.display();
        } 
      } 
      if (event.type == sf::Event::TextEntered && event.text.unicode < 128) {
        window.clear();
        std::string input;
        input = static_cast<char>(event.text.unicode);  
        displayButtons(window, button_area);
        TextEntering(window, input, all_txt, count_output_txt, 0);
      }
    }
  }
}

int main()
{
  frontend();
  return 0;

}