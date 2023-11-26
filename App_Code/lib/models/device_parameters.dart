import 'package:json_annotation/json_annotation.dart';
import 'oven_parameters.dart';

part 'device_parameters.g.dart';

@JsonSerializable()
class DeviceParameters {
  final String owner;
  final bool online;
  final OvenParameters state;
  final String type;

  DeviceParameters(this.owner, this.online, this.state, this.type);

  /// Connect the generated [_$DeviceParametersFromJson] function to the `fromJson`
  /// factory.
  factory DeviceParameters.fromJson(Map<String, dynamic> json) =>
      _$DeviceParametersFromJson(json);

  /// Connect the generated [_$DeviceParametersToJson] function to the `toJson` method.
  Map<String, dynamic> toJson() => _$DeviceParametersToJson(this);
}
