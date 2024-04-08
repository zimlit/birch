#include <metal_stdlib>

using namespace metal;

#include "shaderTypes.h"

struct VertexOut {
    float4 position [[position]];
    float4 color;
};

vertex VertexOut vertexShader(uint vid [[vertex_id]],
                               constant Vertex *vertex_array [[buffer(0)]], constant VertexUniforms &uniforms [[buffer(1)]]) {
    // todo convert points to ndc
    VertexOut out;
    out.position = vector_float4(((vertex_array[vid].position.x/uniforms.pointsWide) - 0.5)*2, ((vertex_array[vid].position.y/uniforms.pointsHigh) - 0.5)*2, 0.0, 1.0);
    out.color = vertex_array[vid].color;
    return out;
}

fragment float4 fragmentShader(VertexOut in [[stage_in]]) {
    return in.color;
}
