#include <metal_stdlib>

using namespace metal;

#include "shaderTypes.h"

struct VertexOut {
    float4 position [[position]];
    float4 color;
};

vertex VertexOut vertexShader(uint vid [[vertex_id]],
                               constant Vertex *vertex_array [[buffer(0)]]) {
    VertexOut out;
    out.position = vector_float4(vertex_array[vid].position.xy, 0.0, 1.0);;
    out.color = vertex_array[vid].color;
    return out;
}

fragment float4 fragmentShader(VertexOut in [[stage_in]]) {
    return in.color;
}
