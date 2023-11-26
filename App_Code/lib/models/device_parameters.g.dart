// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'device_parameters.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

DeviceParameters _$DeviceParametersFromJson(Map<String, dynamic> json) =>
    DeviceParameters(
      json['owner'] as String,
      json['online'] as bool,
      OvenParameters.fromJson(json['state']),
      json['type'] as String,
    );

Map<String, dynamic> _$DeviceParametersToJson(DeviceParameters instance) =>
    <String, dynamic>{
      'owner': instance.owner,
      'online': instance.online,
      'state': instance.state,
      'type': instance.type,
    };
