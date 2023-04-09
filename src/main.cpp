#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow Window(sf::VideoMode(640, 480), L"Rhythm Game Engine", sf::Style::Default);
    sf::Clock Clock;

    srand(time(NULL));

    sf::CircleShape Arrow(25);
    Arrow.setOrigin(25, 25);

    sf::CircleShape Receptor(25);
    Receptor.setOrigin(25, 25);

    Receptor.setFillColor(sf::Color(0, 0, 0, 0));
    Receptor.setOutlineColor(sf::Color::White);
    Receptor.setOutlineThickness(5);

    unsigned NumOfEachArrs = 1000;

    std::vector<int> Left, Down, Up, Right;
    Left.reserve(NumOfEachArrs);
    Down.reserve(NumOfEachArrs);
    Up.reserve(NumOfEachArrs);
    Right.reserve(NumOfEachArrs);

    unsigned Previous = 4;

    for (unsigned i = 0; i < NumOfEachArrs; i++)
    {
        /*Left[i] = rand() * 3;
        Down[i] = rand() * 3;
        Up[i] = rand() * 3;
        Right[i] = rand() * 3;*/

        unsigned Side = rand() % 4;

        do
        {
            Side = rand() % 4;
        }
        while (Side == Previous);

        Previous = Side;

        switch (Side)
        {
            case 0:
                Left[i] = i * 75.f + 1000;
                break;

            case 1:
                Down[i] = i * 75.f + 1000;
                break;

            case 2:
                Up[i] = i * 75.f + 1000;
                break;

            case 3:
                Right[i] = i * 75.f + 1000;
                break;

            default:
                break;
        }
    }

    std::sort(Left.begin(), Left.end());
    std::sort(Down.begin(), Down.end());
    std::sort(Up.begin(), Up.end());
    std::sort(Right.begin(), Right.end());

    unsigned Ridiculous = 0;
    unsigned Marvelous = 0;
    unsigned Perfect = 0;
    unsigned Great = 0;
    unsigned Good = 0;
    unsigned Boo = 0;
    unsigned Miss = 0;

    sf::Font Font;
    Font.loadFromFile("C:/Windows/Fonts/comic.ttf");

    sf::Text Judgments(L"RD: " + sf::String(std::to_string(Ridiculous)) + "\nMA: " + sf::String(std::to_string(Marvelous))  + "\nPF: " + sf::String(std::to_string(Perfect))  + "\nGR: " + sf::String(std::to_string(Great)) + "\nGD: " + sf::String(std::to_string(Good))  + "\nBD: " + sf::String(std::to_string(Boo)) + "\nMS: " + sf::String(std::to_string(Miss)), Font);
    sf::Text Judgment("", Font);

    while (Window.isOpen())
    {
        sf::Event Event;

        while (Window.pollEvent(Event))
        {
            switch (Event.type)
            {
                case sf::Event::Closed:
                    Window.close();
                    break;

                case sf::Event::KeyPressed:

                    switch (Event.key.code)
                    {
                        case sf::Keyboard::Z:
                            {
                                float Timing = 33000;
                                unsigned Index = 0;

                                for (unsigned i = 0; i < NumOfEachArrs; i++)
                                {
                                    float Check = Clock.getElapsedTime().asMilliseconds() - Left[i];

                                    if (abs(Check) < abs(Timing))
                                    {
                                        Timing = Check;
                                        Index = i;
                                    }
                                }

                                if (abs(Timing) <= 180.f)
                                {
                                    Left[Index] = -1;

                                    if (abs(Timing) <= 11.25f)
                                    {
                                        Ridiculous++;
                                        Judgment.setString(L"Ridiculous!!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 11.25f && abs(Timing) <= 22.5f)
                                    {
                                        Marvelous++;
                                        Judgment.setString(L"Marvelous!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 22.5f && abs(Timing) <= 45.f)
                                    {
                                        Judgment.setString(L"Perfect!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 45.f && abs(Timing) <= 90.f)
                                    {
                                        Judgment.setString(L"Great\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 90.f && abs(Timing) <= 135.f)
                                    {
                                        Judgment.setString(L"Good\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 135.f)
                                    {
                                        Judgment.setString(L"Boo\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                }
                            }
                            break;

                        case sf::Keyboard::X:
                            {
                                float Timing = 33000;
                                unsigned Index = 0;

                                for (unsigned i = 0; i < NumOfEachArrs; i++)
                                {
                                    float Check = Clock.getElapsedTime().asMilliseconds() - Down[i];

                                    if (abs(Check) < abs(Timing))
                                    {
                                        Timing = Check;
                                        Index = i;
                                    }
                                }

                                if (abs(Timing) <= 180.f)
                                {
                                    Down[Index] = -1;

                                    if (abs(Timing) <= 11.25f)
                                    {
                                        Ridiculous++;
                                        Judgment.setString(L"Ridiculous!!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 11.25f && abs(Timing) <= 22.5f)
                                    {
                                        Marvelous++;
                                        Judgment.setString(L"Marvelous!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 22.5f && abs(Timing) <= 45.f)
                                    {
                                        Perfect++;
                                        Judgment.setString(L"Perfect!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 45.f && abs(Timing) <= 90.f)
                                    {
                                        Great++;
                                        Judgment.setString(L"Great\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 90.f && abs(Timing) <= 135.f)
                                    {
                                        Good++;
                                        Judgment.setString(L"Good\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 135.f)
                                    {
                                        Boo++;
                                        Judgment.setString(L"Boo\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                }
                            }
                            break;

                        case sf::Keyboard::Comma:
                            {
                                float Timing = 33000;
                                unsigned Index = 0;

                                for (unsigned i = 0; i < NumOfEachArrs; i++)
                                {
                                    float Check = Clock.getElapsedTime().asMilliseconds() - Up[i];

                                    if (abs(Check) < abs(Timing))
                                    {
                                        Timing = Check;
                                        Index = i;
                                    }
                                }

                                if (abs(Timing) <= 180.f)
                                {
                                    Up[Index] = -1;

                                    if (abs(Timing) <= 11.25f)
                                    {
                                        Ridiculous++;
                                        Judgment.setString(L"Ridiculous!!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 11.25f && abs(Timing) <= 22.5f)
                                    {
                                        Marvelous++;
                                        Judgment.setString(L"Marvelous!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 22.5f && abs(Timing) <= 45.f)
                                    {
                                        Perfect++;
                                        Judgment.setString(L"Perfect!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 45.f && abs(Timing) <= 90.f)
                                    {
                                        Great++;
                                        Judgment.setString(L"Great\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 90.f && abs(Timing) <= 135.f)
                                    {
                                        Good++;
                                        Judgment.setString(L"Good\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 135.f)
                                    {
                                        Boo++;
                                        Judgment.setString(L"Boo\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                }
                            }
                            break;

                        case sf::Keyboard::Period:
                            {
                                float Timing = 33000;
                                unsigned Index = 0;

                                for (unsigned i = 0; i < NumOfEachArrs; i++)
                                {
                                    float Check = Clock.getElapsedTime().asMilliseconds() - Right[i];

                                    if (abs(Check) < abs(Timing))
                                    {
                                        Timing = Check;
                                        Index = i;
                                    }
                                }

                                if (abs(Timing) <= 180.f)
                                {
                                    Right[Index] = -1;

                                    if (abs(Timing) <= 11.25f)
                                    {
                                        Ridiculous++;
                                        Judgment.setString(L"Ridiculous!!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 11.25f && abs(Timing) <= 22.5f)
                                    {
                                        Marvelous++;
                                        Judgment.setString(L"Marvelous!!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 22.5f && abs(Timing) <= 45.f)
                                    {
                                        Perfect++;
                                        Judgment.setString(L"Perfect!\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 45.f && abs(Timing) <= 90.f)
                                    {
                                        Great++;
                                        Judgment.setString(L"Great\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 90.f && abs(Timing) <= 135.f)
                                    {
                                        Good++;
                                        Judgment.setString(L"Good\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                    else if (abs(Timing) > 135.f)
                                    {
                                        Boo++;
                                        Judgment.setString(L"Boo\n" + sf::String(std::to_string(Timing)));
                                        Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                                        Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                                    }
                                }
                            }
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }

        for (unsigned i = 0; i < NumOfEachArrs; i++)
        {
            float Timing = 0;

            float CheckLeft = Clock.getElapsedTime().asMilliseconds() - Left[i];
            float CheckDown = Clock.getElapsedTime().asMilliseconds() - Down[i];
            float CheckUp = Clock.getElapsedTime().asMilliseconds() - Up[i];
            float CheckRight = Clock.getElapsedTime().asMilliseconds() - Right[i];

            if (CheckLeft >= 180.f && Left[i] != -1)
            {
                Left[i] = -1;
                Timing = CheckLeft;
            }

            if (CheckDown >= 180.f && Down[i] != -1)
            {
                Down[i] = -1;
                Timing = CheckDown;
            }

            if (CheckUp >= 180.f && Up[i] != -1)
            {
                Up[i] = -1;
                Timing = CheckUp;
            }

            if (CheckRight >= 180.f && Right[i] != -1)
            {
                Right[i] = -1;
                Timing = CheckRight;
            }

            if (Timing >= 180.f)
            {
                Judgment.setString(L"Miss\n" + sf::String(std::to_string(Timing)));
                Judgment.setOrigin(Judgment.getLocalBounds().width / 2, Judgment.getLocalBounds().height / 2);
                Judgment.setPosition(Window.getDefaultView().getCenter().x, Window.getDefaultView().getCenter().y);
                Miss++;
            }
        }

        if (Clock.getElapsedTime().asMilliseconds() >= 64500)
            Window.close();

        Judgments.setString(L"RD: " + sf::String(std::to_string(Ridiculous)) + "\nMA: " + sf::String(std::to_string(Marvelous))  + "\nPF: " + sf::String(std::to_string(Perfect))  + "\nGR: " + sf::String(std::to_string(Great)) + "\nGD: " + sf::String(std::to_string(Good))  + "\nBD: " + sf::String(std::to_string(Boo)) + "\nMS: " + sf::String(std::to_string(Miss)));

        Window.clear();

        for (unsigned i = 0; i < NumOfEachArrs; i++)
        {
            Arrow.setPosition(320 - 30 - 60, 480 - (Clock.getElapsedTime().asMilliseconds() + (480 - 35) - Left[i]));
            Window.draw(Arrow);
        }

        for (unsigned i = 0; i < NumOfEachArrs; i++)
        {
            Arrow.setPosition(320 - 30, 480 - (Clock.getElapsedTime().asMilliseconds() + (480 - 35) - Down[i]));
            Window.draw(Arrow);
        }

        for (unsigned i = 0; i < NumOfEachArrs; i++)
        {
            Arrow.setPosition(320 + 30, 480 - (Clock.getElapsedTime().asMilliseconds() + (480 - 35) - Up[i]));
            Window.draw(Arrow);
        }

        for (unsigned i = 0; i < NumOfEachArrs; i++)
        {
            Arrow.setPosition(320 + 30 + 60, 480 - (Clock.getElapsedTime().asMilliseconds() + (480 - 35) - Right[i]));
            Window.draw(Arrow);
        }

        for (unsigned i = 0; i < 4; i++)
        {
            Receptor.setPosition(320 - 30 - 60 + i * 60, 35);
            Window.draw(Receptor);
        }

        Window.draw(Judgments);
        Window.draw(Judgment);

        Window.display();
    }

    return 0;
}
