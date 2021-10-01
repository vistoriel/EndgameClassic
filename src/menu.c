//menu.c

#include "menu_main.h"

void menu_main_init(t_game *game) {
    game->control.start = 0;
    game->death_timer = 0;
}

void menu_main_logic(t_game *game) {
    int x = game->death_timer;
    x++;
    // if (game->control.start) {
    //     menu_loading_to_game(game);
    // }
}

void menu_main_draw(t_game *game) {
    SDL_Texture *texture;
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = SCREEN_WIDTH;
    rect.h = SCREEN_HEIGHT / 3;

    if (game->control.start == 0) {
        texture = IMG_LoadTexture(game->renderer, "assets/sprites/menu_img2.gif");
        blit(game, texture, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 1.75, ANCHOR_CENTER_CENTER);
        SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(game->renderer, &rect);

        rect.y = SCREEN_HEIGHT / 1.5;
        rect.w = SCREEN_WIDTH;
        rect.h = SCREEN_HEIGHT;

        SDL_RenderFillRect(game->renderer, &rect);

        text_draw(game, "ENDGAME", SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 7, 144);
        text_draw(game, "Press RETURN for start", SCREEN_WIDTH / 1.2 - 24, SCREEN_HEIGHT - 18, 18);

        rect.y = 0;
        rect.w = SCREEN_WIDTH;
        rect.h = SCREEN_HEIGHT;
    }
    else {
        if (game->death_timer == 0 && game->control.start) game->death_timer = SDL_GetTicks();

        if (SDL_GetTicks() < game->death_timer + 3000 && game->control.start) {
            SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
            SDL_RenderFillRect(game->renderer, &rect);
            text_draw(game, "LOADIG...", SCREEN_WIDTH / 1.1 - 24, SCREEN_HEIGHT - 18, 18);
        }

        if (SDL_GetTicks() > game->death_timer + 3000) {
            game->death_timer = 0;
            game->is_started = true;
        }
    }
    
    
    

    
}

// void menu_loading_to_game(t_game *game) {
//     SDL_Rect rect;
//     rect.x = 0;
//     rect.y = 0;
//     rect.w = SCREEN_WIDTH;
//     rect.h = SCREEN_HEIGHT;


    
// }