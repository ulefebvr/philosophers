#include <SFML/Audio.h>
#include <SFML/Graphics.h>

// Il faut créer plusieur sprite, pour chaque philo et n'utiliser qu'une seule texture.
// En effet, il est conseiller d'utiliser le moins de texture possible, car celle ci est mallocé
// alors que les sprites ne sont que des pointeurs vers la texture.
// Il est également préférable de créer plusieurs sprite plutot que d'en utiliser un seul et le modifier,
// car un sprite n'est qu'un pointeur vers tout ou partie de la texture alors qu'une modification du sprite entraine
// une transformation matricielle à chaque changement de paramètre.
// voir: https://openclassrooms.com/forum/sujet/affichage-sprites-sfml-pluseur-fois-68099

int main()
{
    sfVideoMode mode = {1296, 277, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    // sfFont* font;
    // sfText* text;
    // sfMusic* music;
    sfEvent event;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return 0;
    /* Load a sprite to display */
	sfIntRect area = {0, 0, 433, 0};
    texture = sfTexture_createFromFile("frame_philo_plus.jpg", &area);
    if (!texture)
        return 0;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setScale(sprite, (sfVector2f){0.42758, 0.4255});
	sfSprite_setPosition(sprite, (sfVector2f){185, 0});
    /* Create a graphical text to display */
    // font = sfFont_createFromFile("arial.ttf");
    // if (!font)
    //     return 0;
    // text = sfText_create();
    // sfText_setString(text, "Hello SFML");
    // sfText_setFont(text, font);
    // sfText_setCharacterSize(text, 50);
    /* Load a music to play */
    // music = sfMusic_createFromFile("nice_music.ogg");
    // if (!music)
    //     return 0;
    // /* Play the music */
    // sfMusic_play(music);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        /* Draw the sprite */
        sfRenderWindow_drawSprite(window, sprite, NULL);
		sleep(2);

        // /* Draw the text */
        // sfRenderWindow_drawText(window, text, NULL);
        /* Update the window */
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    // sfMusic_destroy(music);
    // sfText_destroy(text);
    // sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 1;
}
