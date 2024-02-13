#ifndef SEASON_H
#define SEASON_H

enum Season
{
  Winter,
  Spring,
  Summer,
  Fall
};

inline string seasonToString(Season season)
{
  switch (season)
  {
  case Season::Spring:
    return "Spring";
  case Season::Summer:
    return "Summer";
  case Season::Fall:
    return "Fall";
  case Season::Winter:
  default:
    return "Winter";
  }
}

inline int seasonToInt(string seasonStr)
{
  if (seasonStr == "Spring")
    return 1;
  if (seasonStr == "Summer")
    return 2;
  if (seasonStr == "Fall")
    return 3;

  return 0;
}

#endif