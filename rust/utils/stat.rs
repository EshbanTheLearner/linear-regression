pub fn mean(values : &Vec<f32>) -> f32 {
    if values.len() == 0 {
        return 0f32;
    }
    return values.iter().sum::<f32>() / (values.len() as f32);
}

pub fn variance(values : &Vec<f32>) -> f32 {
    if values.len() == 0 {
        return 0f32;
    }
    let mean = mean(values);
    return values.iter()
            .map(|x| f32::powf(x - mean, 2 as f32))
            .sum::<f32>() / values.len() as f32;
}