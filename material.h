#ifndef MATERIAL_H
#define MATERIAL_H

struct Material {
  float ambient[4];
  float diffuse[4];
  float specular[4];
  float shininess;
};

const Material BRASS = {{0.33f, 0.22f, 0.03f, 1.00f},
                        {0.78f, 0.57f, 0.11f, 1.00f},
                        {0.99f, 0.91f, 0.81f, 1.00f},
                        27.80f};

const Material WHITE_SHINY = {{1.00f, 1.00f, 1.00f, 1.00f},
                              {1.00f, 1.00f, 1.00f, 1.00f},
                              {1.00f, 1.00f, 1.00f, 1.00f},
                              99.00f};

const Material BRONZE = {{0.21f, 0.13f, 0.05f, 1.00f},
                         {0.72f, 0.43f, 0.18f, 1.00f},
                         {0.39f, 0.27f, 0.17f, 1.00f},
                         25.60f};

const Material WOOD = {{0.33f, 0.22f, 0.03f, 1.00f},
                       {0.73f, 0.48f, 0.34f, 1.00f},
                       {0.57f, 0.36f, 0.30f, 1.00f},
                       27.90f};

const Material RED_PLASTIC = {{0.00f, 0.00f, 0.00f, 1.00f},
                              {0.50f, 0.00f, 0.00f, 1.00f},
                              {0.70f, 0.60f, 0.60f, 1.00f},
                              32.00f};

const Material SILVER = {{0.19f, 0.19f, 0.19f, 1.00f},
                         {0.51f, 0.51f, 0.51f, 1.00f},
                         {0.51f, 0.51f, 0.51f, 1.00f},
                         51.20f};

const Material CYAN_PLASTIC = {{0.00f, 0.10f, 0.06f, 1.00f},
                               {0.00f, 0.51f, 0.51f, 1.00f},
                               {0.50f, 0.50f, 0.50f, 1.00f},
                               32.00f};

const Material BLACK_RUBBER = {{0.02f, 0.02f, 0.02f, 1.00f},
                               {0.01f, 0.01f, 0.01f, 1.00f},
                               {0.40f, 0.40f, 0.40f, 1.00f},
                               10.00f};

const Material GREEN_PLASTIC = {{0.00f, 0.00f, 0.00f, 1.00f},
                                {0.10f, 0.35f, 0.10f, 1.00f},
                                {0.45f, 0.55f, 0.45f, 1.00f},
                                32.00f};

const Material WHITE_PLASTIC = {{0.00f, 0.00f, 0.00f, 1.00f},
                                {0.55f, 0.55f, 0.55f, 1.00f},
                                {0.70f, 0.70f, 0.70f, 1.00f},
                                32.00f};

const Material YELLOW_PLASTIC = {{0.00f, 0.00f, 0.00f, 1.00f},
                                 {0.50f, 0.50f, 0.00f, 1.00f},
                                 {0.60f, 0.60f, 0.50f, 1.00f},
                                 32.00f};

const Material GOLD = {{0.25f, 0.20f, 0.07f, 1.00f},
                       {0.75f, 0.61f, 0.23f, 1.00f},
                       {0.63f, 0.56f, 0.67f, 1.00f},
                       51.20f};

#endif