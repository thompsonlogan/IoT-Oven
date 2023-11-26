import 'package:json_annotation/json_annotation.dart';

part 'oven_parameters.g.dart';

@JsonSerializable()
class OvenParameters {
  final String currentCookingMode;
  final int timerRemainingSec;
  final int temperatureAmbientCelsius;
  final int temperatureSetpointCelsius;
  final bool on;
  final bool start;

  OvenParameters(
      this.currentCookingMode,
      this.timerRemainingSec,
      this.temperatureAmbientCelsius,
      this.temperatureSetpointCelsius,
      this.on,
      this.start);

  /// Connect the generated [_$OvenParametersFromJson] function to the `fromJson`
  /// factory.
  factory OvenParameters.fromJson(Map<String, dynamic> json) =>
      _$OvenParametersFromJson(json);

  /// Connect the generated [_$OvenParametersToJson] function to the `toJson` method.
  Map<String, dynamic> toJson() => _$OvenParametersToJson(this);
}
