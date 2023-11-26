// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'oven_parameters.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

OvenParameters _$OvenParametersFromJson(Map<String, dynamic> json) =>
    OvenParameters(
      json['currentCookingMode'] as String,
      json['timerRemainingSec'] as int,
      json['temperatureAmbientCelsius'] as int,
      json['temperatureSetpointCelsius'] as int,
      json['on'] as bool,
      json['start'] as bool,
    );

Map<String, dynamic> _$OvenParametersToJson(OvenParameters instance) =>
    <String, dynamic>{
      'currentCookingMode': instance.currentCookingMode,
      'timerRemainingSec': instance.timerRemainingSec,
      'temperatureAmbientCelsius': instance.temperatureAmbientCelsius,
      'temperatureSetpointCelsius': instance.temperatureSetpointCelsius,
      'on': instance.on,
      'start': instance.start,
    };
