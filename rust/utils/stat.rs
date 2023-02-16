pub fn mean(values : &Vec<f32>) -> f32 {
    if values.len() == 0 {
        return 0f32;
    }
    return values.iter().sum::<f32>() / (values.len() as f32);
}