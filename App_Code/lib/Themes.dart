import 'package:flutter/material.dart';

enum Themes { Spectrum, Light, Dark }

Color getPrimaryColor(Themes theme) {
  if (theme == Themes.Spectrum) {
    return Color(0xFF4444D9);
  } else if (theme == Themes.Light) {
    return Color(0xFFFFFFFF);
  } else //if(theme == Themes.Dark)
  {
    return Color(0xFF555555);
  }
}

Color getSecondaryColor(Themes theme) {
  if (theme == Themes.Spectrum) {
    return Colors.white;
  } else if (theme == Themes.Light) {
    return Colors.black;
  } else //if(theme == Themes.Dark)
  {
    return Colors.white;
  }
}

Color getTertiaryColor(Themes theme) {
  if (theme == Themes.Spectrum) {
    return Color(0xFF555555);
  } else if (theme == Themes.Light) {
    return Colors.lightBlueAccent;
  } else //if(theme == Themes.Dark)
  {
    return Colors.white60;
  }
}

Color getQuaternaryColor(Themes theme) {
  if (theme == Themes.Spectrum) {
    return Colors.green;
  } else if (theme == Themes.Light) {
    return Colors.yellow;
  } else //if(theme == Themes.Dark)
  {
    return Color(0x7f00bf);
  }
}
